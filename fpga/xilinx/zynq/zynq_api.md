假设外设名为：name

#  文件
* xnameps.h
* xnameps.c

* xname_sinit.c
  - XNamePs_ConfigTable()
  - XNamePs_LookupConfig()


# 重要数据结构
* XNamePs
* XNamePs_Config

# 常规使用流程
1. 声明数据结构实例或指针
```c
XNamePs Name_Ps;
XNamePs_Config *Config;
```

2. 根据设备ID查找设备
```c
Config = XNamePs_LookupConfig(DeviceId);
if (NULL == Config) {
    return XST_FAILURE;
}
```

3. 初始化设备
```c
Status = XNamePs_CfgInitialize(&Name_Ps, Config, Config->BaseAddress);
if (Status != XST_SUCCESS) {
    return XST_FAILURE;
}
```
