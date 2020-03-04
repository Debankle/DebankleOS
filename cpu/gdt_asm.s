global load_gdt

load_gdt:
    mov eax, [esp + 4]
    lgdt [eax]

    jmp 0x08:.reload_segments

.reload_segments:
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov gs, ax
    mov fs, ax
    ret



; no longer needed

; ---------------------- ;
; Global Desciptor Table ;
; ---------------------- ;
; NULL_DESC:
;     dd 0
;     dd 0

; CODE_DESC:
;     dw 0xFFFF       ; limit low
;     dw 0            ; base low
;     db 0            ; base middle
;     db 10011010b    ; access
;     db 11001111b    ; granularity
;     db 0            ; base high

; DATA_DESC:
;     dw 0xFFFF       ; limit low
;     dw 0            ; base low
;     db 0            ; base middle
;     db 10010010b    ; access
;     db 11001111b    ; granularity
;     db 0            ; base high

; gdtr:
;     Limit dw gdtr - NULL_DESC - 1 ; length of GDT
;     Base dd NULL_DESC   ; base of GDT

; no longer needed