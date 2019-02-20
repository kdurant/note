	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	call	CreateStack@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	Push@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$20, %edi
	call	Push@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$30, %edi
	call	Push@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	Top@PLT
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	Pop@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	Top@PLT
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	Top@PLT
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
