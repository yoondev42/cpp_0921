a.out:
(__TEXT,__text) section
_main:
0000000100003f30	pushq	%rbp
0000000100003f31	movq	%rsp, %rbp
0000000100003f34	subq	$0x10, %rsp
0000000100003f38	movl	$0xa, %edi
0000000100003f3d	movl	$0x14, %esi
0000000100003f42	callq	0x100003f82 ## symbol stub for: __Z3addii
0000000100003f47	movl	%eax, -0x4(%rbp)
0000000100003f4a	movl	-0x4(%rbp), %esi
0000000100003f4d	leaq	0x56(%rip), %rdi ## literal pool for: "%d\n"
0000000100003f54	movb	$0x0, %al
0000000100003f56	callq	0x100003f88 ## symbol stub for: _printf
0000000100003f5b	xorl	%ecx, %ecx
0000000100003f5d	movl	%eax, -0x8(%rbp)
0000000100003f60	movl	%ecx, %eax
0000000100003f62	addq	$0x10, %rsp
0000000100003f66	popq	%rbp
0000000100003f67	retq
0000000100003f68	nopl	(%rax,%rax)
__Z3addii:
0000000100003f70	pushq	%rbp
0000000100003f71	movq	%rsp, %rbp
0000000100003f74	movl	%edi, -0x4(%rbp)
0000000100003f77	movl	%esi, -0x8(%rbp)
0000000100003f7a	movl	-0x4(%rbp), %eax
0000000100003f7d	addl	-0x8(%rbp), %eax
0000000100003f80	popq	%rbp
0000000100003f81	retq
