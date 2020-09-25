; 정적 바인딩
a.out:
(__TEXT,__text) section
_main:
0000000100003f60        pushq   %rbp
0000000100003f61        movq    %rsp, %rbp
0000000100003f64        subq    $0x10, %rsp
0000000100003f68        leaq    -0x8(%rbp), %rax
0000000100003f6c        movq    %rax, -0x10(%rbp)
0000000100003f70        movq    -0x10(%rbp), %rdi
0000000100003f74        callq   0x100003f9a ## symbol stub for: __ZN6Animal3fooEv
0000000100003f79        xorl    %eax, %eax
0000000100003f7b        addq    $0x10, %rsp
0000000100003f7f        popq    %rbp
0000000100003f80        retq
0000000100003f81        nopw    %cs:(%rax,%rax)
0000000100003f8b        nopl    (%rax,%rax)
__ZN6Animal3fooEv:
0000000100003f90        pushq   %rbp
0000000100003f91        movq    %rsp, %rbp
0000000100003f94        movq    %rdi, -0x8(%rbp)
0000000100003f98        popq    %rbp
0000000100003f99        retq

; 동적 바인딩
a.out:
(__TEXT,__text) section
_main:
0000000100003ef0        pushq   %rbp
0000000100003ef1        movq    %rsp, %rbp
0000000100003ef4        subq    $0x10, %rsp
0000000100003ef8        leaq    -0x8(%rbp), %rdi
0000000100003efc        callq   __ZN3DogC1Ev ## Dog::Dog()
0000000100003f01        leaq    -0x8(%rbp), %rax
0000000100003f05        movq    %rax, -0x10(%rbp)
0000000100003f09        movq    -0x10(%rbp), %rax
0000000100003f0d        movq    (%rax), %rcx
0000000100003f10        movq    %rax, %rdi
0000000100003f13        callq   *(%rcx)
0000000100003f15        xorl    %eax, %eax
0000000100003f17        addq    $0x10, %rsp
0000000100003f1b        popq    %rbp
0000000100003f1c        retq
0000000100003f1d        nopl    (%rax)
__ZN3DogC1Ev:
0000000100003f20        pushq   %rbp
0000000100003f21        movq    %rsp, %rbp
0000000100003f24        subq    $0x10, %rsp
0000000100003f28        movq    %rdi, -0x8(%rbp)
0000000100003f2c        movq    -0x8(%rbp), %rdi
0000000100003f30        callq   __ZN3DogC2Ev ## Dog::Dog()
0000000100003f35        addq    $0x10, %rsp
0000000100003f39        popq    %rbp
0000000100003f3a        retq
0000000100003f3b        nopl    (%rax,%rax)
__ZN3DogC2Ev:
0000000100003f40        pushq   %rbp
0000000100003f41        movq    %rsp, %rbp
0000000100003f44        subq    $0x10, %rsp
0000000100003f48        movq    %rdi, -0x8(%rbp)
0000000100003f4c        movq    -0x8(%rbp), %rax
0000000100003f50        movq    %rax, %rcx
0000000100003f53        movq    %rcx, %rdi
0000000100003f56        movq    %rax, -0x10(%rbp)
0000000100003f5a        callq   __ZN6AnimalC2Ev ## Animal::Animal()
0000000100003f5f        movq    0x9a(%rip), %rax
0000000100003f66        addq    $0x10, %rax
0000000100003f6c        movq    -0x10(%rbp), %rcx
0000000100003f70        movq    %rax, (%rcx)
0000000100003f73        addq    $0x10, %rsp
0000000100003f77        popq    %rbp
0000000100003f78        retq
0000000100003f79        nopl    (%rax)
__ZN6AnimalC2Ev:
0000000100003f80        pushq   %rbp
0000000100003f81        movq    %rsp, %rbp
0000000100003f84        movq    0x7d(%rip), %rax
0000000100003f8b        addq    $0x10, %rax
0000000100003f91        movq    %rdi, -0x8(%rbp)
0000000100003f95        movq    -0x8(%rbp), %rcx
0000000100003f99        movq    %rax, (%rcx)
0000000100003f9c        popq    %rbp
0000000100003f9d        retq
0000000100003f9e        nop
__ZN6Animal3fooEv:
0000000100003fa0        pushq   %rbp
0000000100003fa1        movq    %rsp, %rbp
0000000100003fa4        movq    %rdi, -0x8(%rbp)
0000000100003fa8        popq    %rbp
0000000100003fa9        retq