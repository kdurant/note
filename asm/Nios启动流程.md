#.globl
```mipsasm
.globl  _name 
```
.globl指示告诉汇编器，_name这个符号要被链接器用到

# .section
`.section ".customtext", "ax"`
定义一个段，每一个段以段名为开始，以`下一个段名`或者文件结尾为结束。ELF格式允许的段标志：

* a：可分配
* w：可写段
* x：执行段
# .align
`.align`的作用在于对指令或者数据的存放地址进行对齐, 它的作用范围只限于紧跟它的那条指令或者数据，而接下来的指令或者数据的地址由上一条指令的地址和其长度决定。
```mipsasm
.align 5
```
2^5=32, 于是汇编器将下一条指令的地址就会安排在下一个32的整数倍的地址上

# .type
用来指定一个符号的类型是函数类型或者是对象类型, 对象类型一般是数据

# .pushsection
这是ELF部分堆栈操作指令之一. 指令将当前section（和subsection）推送到节堆栈的顶部，然后用name和subsection替换当前节和小节

# .int

# .popsection

# .set 

# .equ

```mipsasm

/*************************************************************************\
|                         EXTERNAL REFERENCES                             |
\*************************************************************************/

/*
用户代码的入口点在host模式下是main，在standalone模式下是alt_main。
这里明确引用了这些，以确保它们内置在可执行文件中。 这允许用户将它们构建到库中，而不是在链接时将它们提供在目标文件中。
 */
    .globl main
    .globl alt_main

/*
 * Create a reference to the software multiply/divide and trap handers,
 * so that if they are provided, they will appear in the executable.
 */
#ifndef ALT_NO_INSTRUCTION_EMULATION
    .globl alt_exception_muldiv
#endif
#ifdef ALT_TRAP_HANDLER
    .globl alt_exception_trap
#endif

/*
 * Linker defined symbols used to initialize bss.
 */
.globl __bss_start
.globl __bss_end

/*************************************************************************\
|                         RESET SECTION (.entry)                          |
\*************************************************************************/

/*
这是Nios的复位入口点
在复位时，只有包含复位向量的高速缓存由硬件初始化。 第一个缓存行中的代码初始化其余部分的指令缓存。
 */

    .section .entry, "xa"
    .align 5

/*
明确允许在此代码中使用r1（汇编程序临时寄存器）。 该寄存器通常保留用于汇编程序。
 */
    .set noat

/*
有些工具想知道复位向量的位置。 复位向量并不总是提供代码，但至少__reset标签始终包含复位向量地址，因为它是在.entry部分的开头定义的。
 */

    .globl __reset
    .type __reset, @function
__reset:

/*
如果存在，则初始化指令高速缓存（即大小> 0）并且允许重置代码，除非优化RTL仿真。
RTL仿真可确保指令高速缓存已初始化，因此跳过此循环可加速RTL仿真。
 
当ECC存在时，需要为每个字地址执行initi，以确保缓存RAM中的ECC奇偶校验位得到初始化。
 */

#if NIOS2_ICACHE_SIZE > 0 && defined(ALT_ALLOW_CODE_AT_RESET) && (!defined(ALT_SIM_OPTIMIZE) || defined(NIOS2_ECC_PRESENT))
#if NIOS2_ICACHE_SIZE > 0x8000
    movhi r2, %hi(NIOS2_ICACHE_SIZE)
#else
    movui r2, NIOS2_ICACHE_SIZE
#endif

0:
# 上面将r2的值设置为 NIOS2_ICACHE_SIZE
# 现在个循环将 NIOS2_ICACHE_SIZE - 32
    initi r2        # 初始化指令缓存指令
    addi r2, r2, -NIOS2_ICACHE_LINE_SIZE
    bgt r2, zero, 0b
1:

    /*
以下调试信息告诉ISS不要运行上面的循环，而是使用更快的内部代码执行其操作。
     */
    .pushsection .debug_alt_sim_info
    .int 1, 1, 0b, 1b
    .popsection
#endif /* Initialize Instruction Cache */

/*
如果允许重置代码或优化RTL模拟，则跳转到.text部分的_start入口点。
 */
#if defined(ALT_ALLOW_CODE_AT_RESET) || defined(ALT_SIM_OPTIMIZE)
    /* 跳转到_start */
    movhi r1, %hi(_start)
    ori r1, r1, %lo(_start)
    jmp r1

# 先把_start的高16bit放到r1中, 再把_start的低16bit和 r1的值做或运算, 为什么不直接mov?

    .size __reset, . - __reset
#endif /* Jump to _start */

/*
 * When not using exit, provide an _exit symbol to prevent unresolved
 * references to _exit from the linker script.
 */
#ifdef ALT_NO_EXIT
    .globl _exit
_exit:
#endif

/*************************************************************************\
|                          TEXT SECTION (.text)                           |
\*************************************************************************/

/*
 * Start of the .text section, and also the code entry point when
 * the code is executed by a bootloader rather than directly from reset.
 */
    .section .text
    .align 2

    .globl _start
    .type _start, @function
_start:

#if (NIOS2_NUM_OF_SHADOW_REG_SETS > 0)    
    /*
     * Ensure that the current register set is 0 upon
     * entry to this code.  Switch register set to 0 by
     * writing zero to SSTATUS register and executing an ERET instruction
     * to set STATUS.CRS to 0.
     */
    
    /* Get the current register set number (STATUS.CRS).  status & 0x0000fc00 */
    rdctl r2, status
    andi r2, r2, NIOS2_STATUS_CRS_MSK
    
    /* Skip switching register set if STATUS.CRS is 0.  */
    beq r2, zero, 0f

    /* Set SSTATUS to 0 to get to set SSTATUS.PRS to 0. */
    .set nobreak
    movui sstatus, 0
    .set break

    /* Switch to register set 0 and jump to label. */
    movhi ea, %hi(0f)
    ori ea, ea, %lo(0f)
    eret

0:
#endif /* NIOS2_NUM_OF_SHADOW_REG_SETS > 0 */

/*
 * Initialize the data cache if present (i.e. size > 0).
 * Skip initialization if optimizing for RTL simulation and ECC isn't present.
 * RTL simulations can ensure the data cache tag RAM is already initialized
 * (but not the data RAM for ECC) so skipping this speeds up RTL simulation.
 *
 * When ECC is present, need to execute initd for each word address
 * to ensure ECC parity bits in data RAM get initialized.
 * Otherwise, only need to execute initd for each line address.
 */

#if NIOS2_DCACHE_SIZE > 0 && (!defined(ALT_SIM_OPTIMIZE) || defined(NIOS2_ECC_PRESENT))

    /* Assume the data cache size is always a power of two. */
#if NIOS2_DCACHE_SIZE > 0x8000
    movhi r2, %hi(NIOS2_DCACHE_SIZE)
#else
    movui r2, NIOS2_DCACHE_SIZE
#endif

0:
    initd 0(r2)
#ifdef NIOS2_ECC_PRESENT
    addi r2, r2, -4
#else
    addi r2, r2, -NIOS2_DCACHE_LINE_SIZE
#endif
    bgt r2, zero, 0b
1:

    /*
     * The following debug information tells the ISS not to run the loop above
     * but to perform its actions using faster internal code.
     */
    .pushsection .debug_alt_sim_info
    .int 2, 1, 0b, 1b
    .popsection
#endif /* Initialize Data Cache */

    /* Log that caches have been initialized. */
    ALT_LOG_PUTS(alt_log_msg_cache)

    /* Log that the stack pointer is about to be setup. */
    ALT_LOG_PUTS(alt_log_msg_stackpointer)

    /*
现在初始化了缓存，设置堆栈指针和全局指针。 假设链接器提供的值已正确对齐。
     */
    movhi sp, %hi(__alt_stack_pointer)
    ori sp, sp, %lo(__alt_stack_pointer)
    movhi gp, %hi(_gp)
    ori gp, gp, %lo(_gp)

#ifdef NIOS2_ECC_PRESENT
    /* 
     * Initialize all general-purpose registers so that ECC can be enabled
     * later without accidentally triggering a spurious ECC error.
     */
    movui r1, 0
    movui r2, 0
    movui r3, 0
    movui r4, 0
    movui r5, 0
    movui r6, 0
    movui r7, 0
    movui r8, 0
    movui r9, 0
    movui r10, 0
    movui r11, 0
    movui r12, 0
    movui r13, 0
    movui r14, 0
    movui r15, 0
    movui r16, 0
    movui r17, 0
    movui r18, 0
    movui r19, 0
    movui r20, 0
    movui r21, 0
    movui r22, 0
    movui r23, 0
    /* Skip r24 (et) because only exception handler should write it. */
    /* Skip r25 (bt) because only debugger should write it. */
    /* Skip r26 (gp) because it is already been initialized. */
    /* Skip r27 (sp) because it is already been initialized. */
    movui r28, 0    /* fp */
    movui r29, 0    /* ea */
    .set nobreak
    movui r30, 0    /* sstatus */
    .set break
    movui r31, 0    /* ra */

#endif /* NIOS2_ECC_PRESENT */

#if (NIOS2_NUM_OF_SHADOW_REG_SETS > 0)    
    /* 
     * Setup registers in shadow register sets
     * from 1 to NIOS2_NUM_OF_SHADOW_REG_SETS.
     */

    movui r2, 0     /* Contains value written into STATUS */
    movui r3, NIOS2_NUM_OF_SHADOW_REG_SETS  /* counter */
    movhi r4, 1     /* Constant to increment STATUS.PRS */
    
.Linitialize_shadow_registers:
    /* Increment STATUS.PRS */
    add r2, r2, r4
    wrctl status, r2

    /* Clear r0 in the shadow register set (not done by hardware) */
    wrprs r0, r0

    /* Write the GP in previous register set */
    wrprs gp, gp

    /* 
     * Only write the SP in previous register set
     * if using the separate exception stack. For normal case (single stack),
     * funnel code would read the SP from previous register set with a RDPRS.
     */
#ifdef ALT_INTERRUPT_STACK
    movhi et, %hiadj(__alt_interrupt_stack_pointer)
    addi  et, et, %lo(__alt_interrupt_stack_pointer)
    wrprs sp, et
#endif /* ALT_INTERRUPT_STACK */

#ifdef NIOS2_ECC_PRESENT
    /* 
     * Initialize all general-purpose registers so that ECC can be enabled
     * later without accidentally triggering a spurious ECC error.
     */
    wrprs r1, r0
    wrprs r2, r0
    wrprs r3, r0
    wrprs r4, r0
    wrprs r5, r0
    wrprs r6, r0
    wrprs r7, r0
    wrprs r8, r0
    wrprs r9, r0
    wrprs r10, r0
    wrprs r11, r0
    wrprs r12, r0
    wrprs r13, r0
    wrprs r14, r0
    wrprs r15, r0
    wrprs r16, r0
    wrprs r17, r0
    wrprs r18, r0
    wrprs r19, r0
    wrprs r20, r0
    wrprs r21, r0
    wrprs r22, r0
    wrprs r23, r0
    /* Skip r24 (et) because only exception handler should write it. */
    /* Skip r25 (bt) because only debugger should write it. */
    /* Skip r26 (gp) because it is already been initialized. */
    /* Skip r27 (sp) because it was initialized above or will be by a rdprs if not above */
    wrprs r28, r0    /* fp */
    wrprs r29, r0    /* ea */
    wrprs r30, r0    /* ba */
    wrprs r31, r0    /* ra */
#endif /* NIOS2_ECC_PRESENT */

    /* Decrement shadow register set counter */
    addi r3, r3, -1

    /* Done if index is 0. */
    bne r3, zero, .Linitialize_shadow_registers
#endif /* (NIOS2_NUM_OF_SHADOW_REG_SETS > 0) */

/*
 * Clear the BSS if not optimizing for RTL simulation.
 *
 * This uses the symbols: __bss_start and __bss_end, which are defined
 * by the linker script. They mark the begining and the end of the bss
 * region. The linker script guarantees that these values are word aligned.
 */
#ifndef ALT_SIM_OPTIMIZE
    /* Log that the BSS is about to be cleared. */
    ALT_LOG_PUTS(alt_log_msg_bss)

    movhi r2, %hi(__bss_start)
    ori r2, r2, %lo(__bss_start)

    movhi r3, %hi(__bss_end)
    ori r3, r3, %lo(__bss_end)

    beq r2, r3, 1f

0:
    stw zero, (r2)
    addi r2, r2, 4
    bltu r2, r3, 0b

1:

    /*
     * The following debug information tells the ISS not to run the loop above
     * but to perform its actions using faster internal code.
     */
    .pushsection .debug_alt_sim_info
    .int 3, 1, 0b, 1b
    .popsection
#endif /* ALT_SIM_OPTIMIZE */

/*
 * Turn off the use of r1 (the assembler temporary register)
 * so that call instructions can be safely relaxed across a
 * 256MB boundary if needed
 */
    .set at

/*
 * The alt_load() facility is normally used when there is no bootloader.
 * It copies some sections into RAM so it acts like a mini-bootloader.
 */
#ifdef CALL_ALT_LOAD

#ifdef ALT_STACK_CHECK
    /*
     * If the user has selected stack checking then we need to set up a safe
     * value in the stack limit register so that the relocation functions
     * don't think the stack has overflowed (the contents of the rwdata
     * section aren't defined until alt_load() has been called).
     */
    mov   et, zero
#endif

    call alt_load

#endif /* CALL_ALT_LOAD */

#ifdef ALT_STACK_CHECK
    /*
     * Set up the stack limit (if required).  The linker has set up the
     * copy of the variable which is in memory.
     */

    ldw   et, %gprel(alt_stack_limit_value)(gp)
#endif

    /* Log that alt_main is about to be called. */
    ALT_LOG_PUTS(alt_log_msg_alt_main)

    /* Call the C entry point. It should never return. */
    call alt_main

    /* Wait in infinite loop in case alt_main does return. */
alt_after_alt_main:
    br alt_after_alt_main

    .size _start, . - _start

/*
 * Add information about the stack base if stack overflow checking is enabled.
 */
#ifdef ALT_STACK_CHECK
    .globl  alt_stack_limit_value
    .section .sdata,"aws",@progbits
    .align  2
    .type   alt_stack_limit_value, @object
    .size   alt_stack_limit_value, 4
alt_stack_limit_value:
    .long   __alt_stack_limit
#endif
```
