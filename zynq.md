# MIO
## 概述
* 基址 0xE000A000
![pic]()
MIO上的引脚为复用引脚，ARM上外设也可以使用。
![pic]()

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

# 中断用法
## 1. 声明中断
```c
XScuGic INTCInst;   // 可以是全局变量
```

## 2. 声明
```c
#include "xscugic.h"
#include "xil_exception.h"

XScuGic_Config *IntcConfig;
```

## 3.
```c
IntcConfig = XScuGic_LookupConfig(DeviceId);
```

## 4. 
```c
status = XScuGic_CfgInitialize(&INTCInst, IntcConfig, IntcConfig->CpuBaseAddress);
if(status != XST_SUCCESS)
    return XST_FAILURE;
```

## 5.
```c
Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
        (Xil_ExceptionHandler)XScuGic_InterruptHandler,
        XScuGicInstancePtr);
Xil_ExceptionEnable();
```

## 6.
```c
status = XScuGic_Connect(&INTCInst,
        INTC_GPIO_INTERRUPT_ID,
        (Xil_ExceptionHandler)BTN_Intr_Handler, // 中断处理函数
        (void *)GpioInstancePtr);           // 需要中断的对象
if(status != XST_SUCCESS)
    return XST_FAILURE;
```

## 7.
```c
XGpio_InterruptEnable(GpioInstancePtr, 1);
XGpio_InterruptGlobalEnable(GpioInstancePtr);
XScuGic_Enable(&INTCInst, INTC_GPIO_INTERRUPT_ID);

## 8.
```c
void BTN_Intr_Handler(void *InstancePtr)
{
	unsigned char led_val = 0;

	if( (XGpio_InterruptGetStatus(&BTNInst) & BTN_INT) != BTN_INT)
	{
		return ;

		XGpio_InterruptDisable(&BTNInst, BTN_INT);
	}

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
	(void)XGpio_InterruptClear(&BTNInst, BTN_INT);
	XGpio_InterruptEnable(&BTNInst, BTN_INT);
}
```
```