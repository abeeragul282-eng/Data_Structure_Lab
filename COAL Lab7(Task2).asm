.model small
.stack 100h
.data
    num db 3
    msg1 db "Number: 3$"
    msg2 db 13,10,"Cube of Number: 27$"
.code
main proc
    mov ax, @data
    mov ds, ax
    mov dx, offset msg1
    mov ah, 9
    int 21h
    mov dx, offset msg2
    mov ah, 9
    int 21h
    mov ah, 4ch
    int 21h
main endp
end main