.model small
.stack 100h
.data
    val db 25
    q1 db ?
    r1 db ?
    str1 db "Number: 25$"
    str2 db 13,10,"Divide by 10$"
    str3 db 13,10,"Quotient = $"
    str4 db 13,10,"Remainder = $"

.code
main proc
    mov ax, @data
    mov ds, ax
    mov ah, 0
    mov al, 3
    int 10h
    lea dx, str1
    mov ah, 9
    int 21h
    lea dx, str2
    mov ah, 9
    int 21h
    mov al, val
    mov cl, 10
    xor ah, ah     
    div cl
    mov q1, al
    mov r1, ah
    lea dx, str3
    mov ah, 9
    int 21h
    mov dl, q1
    add dl, 48
    mov ah, 2
    int 21h
    lea dx, str4
    mov ah, 9
    int 21h
    mov dl, r1
    add dl, 48
    mov ah, 2
    int 21h
    mov ah, 4ch
    int 21h
main endp
end main