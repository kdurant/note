# 通用寄存器

# 段寄存器
## DS

## SS

## SP

# 指令

## mov
```asm
#mov 寄存器, 数据
mov     ax,     8
#mov 寄存器, 寄存器
mov     ax,     bx
#mov 寄存器，内存单元
mov     ax,     [0]
#mov 内存单元，寄存器
mov     [0],    ax
#mov 段寄存器，寄存器
mov     ds,     ax
```