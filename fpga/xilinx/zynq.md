# MIO
## 概述
* 基址 0xE000A000
![pic](https://github.com/kdurant/note/blob/master/res/zynq/MIO_planner.png)
MIO上的引脚为复用引脚，ARM上外设也可以使用。
![pic](https://github.com/kdurant/note/blob/master/res/zynq/MIO_config.png)

## 使用流程
```c
#include "xgpiops.h"
// 1. 声明GPIO指针
static XGpioPs psGpioInstancePtr;
XGpioPs_Config * GpioConfigPtr;

// 2. 使用到的引脚(0-53)
int iPinNumber = 7;

int xStatus;

// 3. 查找配置
GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);

if(GpioConfigPtr == NULL)
	return XST_FAILURE;

// 4. 初始化
xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr, GpioConfigPtr,
		GpioConfigPtr->BaseAddr);

if(XST_SUCCESS != xStatus)
	print("PS GPIO INIT FAILED\n\r");

// 5. IO口设置
XGpioPs_SetDirectionPin(&psGpioInstancePtr, iPinNumber, 0x01);
XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, iPinNumber, 1);

// 6. 简单操作
while(1)
{
	XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 1);
	sleep(1);
	XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 0);
	sleep(1);
}
```

# AXI_GPIO
block设计中添加`AXI_GPIO`IP核
```c
#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"
#define LED_DEVICE_ID		XPAR_AXI_GPIO_0_DEVICE_ID

XGpio LED;

int main(void)
{
	int status;

	status = XGpio_Initialize(&LED, LED_DEVICE_ID);
	if(status != XST_SUCCESS)
		return XST_FAILURE;

	XGpio_SetDataDirection(&LED, 1, 0xff);
	int i = 0;
	while(1)
	{
		XGpio_DiscreteWrite(&LED, 1, 0x01<<i);
		sleep(1);
		i++;
		if(i == 8)
			i = 0;
	}
}
```

# 中断基本用法

## 中断配置
```c
#include "xscugic.h"
#include "xil_exception.h"

// 1. 中断实例和配置参数
static XScuGic INTCInst;   // 全局变量
static XScuGic_Config *IntcConfig;  // 也可以使用局部变量

// 2. 查找配置
IntcConfig = XScuGic_LookupConfig(DeviceId);

// 3. 初始化
status = XScuGic_CfgInitialize(&INTCInst, IntcConfig, IntcConfig->CpuBaseAddress);
if(status != XST_SUCCESS)
    return XST_FAILURE;

Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,			// fixed
        (Xil_ExceptionHandler)XScuGic_InterruptHandler,		// fixed
        &INTCInst);											// 
Xil_ExceptionEnable();

status = XScuGic_Connect(&INTCInst,
        INTC_GPIO_INTERRUPT_ID,
        (Xil_ExceptionHandler)BTN_Intr_Handler, // 中断处理函数
        (void *)GpioInstancePtr);           // 需要中断的对象
if(status != XST_SUCCESS)
    return XST_FAILURE;
```

XGpio_InterruptEnable(GpioInstancePtr, 1); 		// 和具体中断有关
XGpio_InterruptGlobalEnable(GpioInstancePtr);
XScuGic_Enable(&INTCInst, INTC_GPIO_INTERRUPT_ID);
```

## 中断函数流程
```c
void BTN_Intr_Handler(void *InstancePtr)
{
	unsigned char led_val = 0;
	// 1. 禁止中断
	if( (XGpio_InterruptGetStatus(&BTNInst) & XGPIO_IR_CH1_MASK) != XGPIO_IR_CH1_MASK)
	{
		return ;

		XGpio_InterruptDisable(&BTNInst, XGPIO_IR_CH1_MASK);
	}
	// 2. 处理流程
	btn_value = ~XGpio_DiscreteRead(&BTNInst, 1) & 0x1f;
	switch(btn_value)
	{
	case 0x01: led_val = 0x01; break;
	case 0x02: led_val = 0x02; break;
	case 0x04: led_val = 0x04; break;
	case 0x08: led_val = 0x08; break;
	case 0x10: led_val = 0x10; break;
	}

	XGpio_DiscreteWrite(&LED, 1, led_val);

	// 3. 清除中断标志并再次打开中断
	(void)XGpio_InterruptClear(&BTNInst, XGPIO_IR_CH1_MASK);
	XGpio_InterruptEnable(&BTNInst, XGPIO_IR_CH1_MASK);
}
```

# 定时器中断基本用法
```c
#include <stdio.h>

#include "xil_types.h"
#include "Xscugic.h"
#include "xil_exception.h"
#include "xscutimer.h"

#define TIMER_DEVICE_ID		XPAR_XSCUTIMER_0_DEVICE_ID
#define INTC_DEVICE_ID		XPAR_SCUGIC_SINGLE_DEVICE_ID
#define TIMER_IRPT_INTR		XPAR_SCUTIMER_INTR

#define TIMER_LOAD_VALUE	0x13D92D3f

static XScuGic Intc;
static XScuTimer Timer;

static void SetupInterruptSystem(XScuGic *GicInstancePtr,
		XScuTimer *TimerInstancePtr, u16 TimerIntrId);

static void TimerIntrHandler(void *CallBackRef);

int main(void)
{
	XScuTimer_Config *TMRConfigPtr;
	printf("--------------START-------------");

	TMRConfigPtr = XScuTimer_LookupConfig(TIMER_DEVICE_ID);
	XScuTimer_CfgInitialize(&Timer, TMRConfigPtr, TMRConfigPtr->BaseAddr);
	XScuTimer_SelfTest(&Timer);
	XScuTimer_LoadTimer(&Timer, TIMER_LOAD_VALUE);
	XScuTimer_EnableAutoReload(&Timer);
	XScuTimer_Start(&Timer);

	SetupInterruptSystem(&Intc, &Timer, TIMER_IRPT_INTR);

	while(1);
	{

	}

	return 0;
}

void SetupInterruptSystem(XScuGic *GicInstancePtr,
		XScuTimer *TimerInstancePtr, u16 TimerIntrId)
{
	XScuGic_Config *IntcConfig;
	Xil_ExceptionInit();
	IntcConfig = XScuGic_LookupConfig(INTC_DEVICE_ID);
	XScuGic_CfgInitialize(GicInstancePtr, IntcConfig,
			IntcConfig->CpuBaseAddress);

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			(Xil_ExceptionHandler)XScuGic_InterruptHandler,
			GicInstancePtr);

	XScuGic_Connect(GicInstancePtr, TimerIntrId,
			(Xil_ExceptionHandler)TimerIntrHandler,
			(void *)TimerInstancePtr);

	XScuGic_Enable(GicInstancePtr, TimerIntrId);
	XScuTimer_EnableInterrupt(TimerInstancePtr);
	Xil_ExceptionEnableMask(XIL_EXCEPTION_IRQ);
}

static void TimerIntrHandler(void *CallBackRef)
{
	static int sec = 0;

	XScuTimer *TimerInstancePtr = (XScuTimer *)CallBackRef;
	XScuTimer_ClearInterruptStatus(TimerInstancePtr);
	sec++;
	printf("%d Second\n\r", sec);
}
```
