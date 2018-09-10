# 分类
* MIO
    - 只对PS部分可见，PL不可用
    - 分布在Bank0, Bank1
    - 引脚固定
    - 直接由PS操作
* EMIO
    - PS可用，但需要分配引脚。PL可用
    - 分布在Bank2，Bank3
    - 引脚由PL扩展，可直接由PS操作
* AXI_GPIO
    - PS通过M_AXI_GPIO接口控制PL非EMIO，使用时消耗管脚资源和逻辑资源
  

# step 
在zynq配置界面中使能需要用到的IO口
`MIO Configuration` -> `I/O Peripherals` -> `GPIO`

# step
* 声明2个变量
```c
static XGpioPs psGpioInstancePtr;
XGpioPs_Config* GpioConfigPtr;
```

* 设置使用到的引脚和方向

```c
int iPinNumber= 7; //LD9 连接的是 MIO7
u32 uPinDirection = 0x1; //1 表示输出， 0 表示输入
```

# step
```c
GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);  // 根据ID，在配置表中找到此ID对应的GPIO基址。

if(GpioConfigPtr == NULL)
    return XST_FAILURE;

// 初始化
xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr,GpioConfigPtr,
        GpioConfigPtr->BaseAddr);
if(XST_SUCCESS != xStatus)
    print(" PS GPIO INIT FAILED \n\r");
```

# step
```c
XGpioPs_SetDirectionPin(&psGpioInstancePtr, iPinNumber,uPinDirection);// 配 置 MIO 输出方向
XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, iPinNumber,1);//配置 MIO 的第 7 位输出
```

# step
```c
XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 1);//点亮 MIO 的第 7 位输出 1
sleep(1);//延时
XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 0);//熄灭 MIO 的第 7 位输出 0
sleep(1);//延时
```


# example

```c

#include "xgpiops.h"
#include "sleep.h"
int main()
{
    static XGpioPs psGpioInstancePtr;
    XGpioPs_Config* GpioConfigPtr;
    int iPinNumber= 7; //LD9 连接的是 MIO7
    u32 uPinDirection = 0x1; //1 表示输出， 0 表示输入
    int xStatus;
    //--MIO 的初始化
    GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
    if(GpioConfigPtr == NULL)
        return XST_FAILURE;
    xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr,GpioConfigPtr,
            GpioConfigPtr->BaseAddr);
    if(XST_SUCCESS != xStatus)
        print(" PS GPIO INIT FAILED \n\r");
    //--MIO 的输入输出操作
    XGpioPs_SetDirectionPin(&psGpioInstancePtr, iPinNumber,uPinDirection);// 配 置 MIO 输出方向
    XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, iPinNumber,1);//配置 MIO 的第 7 位输出
    while(1)
    {
        XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 1);//点亮 MIO 的第 7 位输出 1
        sleep(1);//延时
        XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 0);//熄灭 MIO 的第 7 位输出 0
        sleep(1);//延时
    }
    return 0;
}
```