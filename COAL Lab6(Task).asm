.model small
.stack 100h
.data
    name1 db "Full Name: Abeera Gul$"
    sap1 db 13,10,"SAP Id: 69253$"
    batch1 db 13,10,"Batch: 2026$"
    program1 db 13,10,"Program: BSSE, Semester: 3$"

.code
main proc
    mov ax, @data
    mov ds, ax
    mov dx, offset name1
    mov ah, 9
    int 21h
    mov dx, offset sap1
    mov ah, 9
    int 21h
    mov dx, offset batch1
    mov ah, 9
    int 21h
    mov dx, offset program1
    mov ah, 9
    int 21h
    mov ah, 4ch
    int 21h
main endp
end main