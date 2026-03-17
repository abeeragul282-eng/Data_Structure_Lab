.model small
.stack 100h
.data
    length db 2
    width db 4
    msg1 db "Length: 2$"
    msg2 db 13,10,"Width: 4$"
    msg3 db 13,10,"Area of Rectangle: $"
    result db ?
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
    mov al, length      
    mov bl, width       
    mul bl              
    mov result, al
    mov dx, offset msg3
    mov ah, 9
    int 21h
    mov dl, result
    add dl, 48          
    mov ah, 2
    int 21h
    mov ah, 4ch
    int 21h
main endp
end main