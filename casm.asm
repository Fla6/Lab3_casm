section .text

global _delarr

_delarr:
        push    rbp
        push    rsp
        mov     rbp, rsp
        mov     DWORD [rbp-20], edi
        mov     DWORD [rbp-24], esi
        mov     DWORD [rbp-28], edx
        mov     DWORD [rbp-4], 0
        jmp     .L2
.L5:
        mov     eax, DWORD [rbp-28]
        mov     DWORD [rbp-8], eax
        jmp     .L3
.L4:
        mov     eax, DWORD [rbp-8]
        add     eax, 1
        movsx   rcx, eax
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, rdx
        sal     rax, 2
        add     rax, rdx
        add     rax, rcx
        mov     ecx, DWORD [rbp-4+rax*4]
        mov     eax, DWORD [rbp-8]
        movsx   rsi, eax
        mov     eax, DWORD [rbp-4]
        movsx   rdx, eax
        mov     rax, rdx
        sal     rax, 2
        add     rax, rdx
        add     rax, rsi
        mov     DWORD [rbp-4+rax*4], ecx
        add     DWORD [rbp-8], 1
.L3:
        mov     eax, DWORD [rbp-20]
        sub     eax, 1
        cmp     DWORD [rbp-8], eax
        jl      .L4
        add     DWORD [rbp-4], 1
.L2:
        mov     eax, DWORD [rbp-4]
        cmp     eax, DWORD [rbp-20]
        jl      .L5
        mov     eax, DWORD [rbp-24]
        mov     DWORD [rbp-12], eax
        jmp     .L6
.L9:
        mov     DWORD [rbp-16], 0
        jmp     .L7
.L8:
        mov     eax, DWORD [rbp-12]
        lea     edx, [rax+1]
        mov     eax, DWORD [rbp-16]
        movsx   rcx, eax
        movsx   rdx, edx
        mov     rax, rdx
        sal     rax, 2
        add     rax, rdx
        add     rax, rcx
        mov     ecx, DWORD [rbp-4+rax*4]
        mov     eax, DWORD [rbp-16]
        movsx   rsi, eax
        mov     eax, DWORD [rbp-12]
        movsx   rdx, eax
        mov     rax, rdx
        sal     rax, 2
        add     rax, rdx
        add     rax, rsi
        mov     DWORD [rbp-4+rax*4], ecx
        add     DWORD [rbp-16], 1
.L7:
        mov     eax, DWORD [rbp-20]
        sub     eax, 1
        cmp     DWORD [rbp-16], eax
        jl      .L8
        add     DWORD [rbp-12], 1
.L6:
        mov     eax, DWORD [rbp-20]
        sub     eax, 1
        cmp     DWORD [rbp-12], eax
        jl      .L9
        mov     rsp, rbp
        pop     rbp
        pop     rsp
        ret