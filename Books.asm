.model small
.stack 100h

.data

Books STRUC
author_name db 50 DUP (?) 
book_title db 50 DUP (?) 
page_count dw ? 
price dw ? 
Books ENDS


B Books <" Lee", "To Kill a Mockingbird", 200, 345>, <"Orwell", "1984", 89, 1100>, <"Palanik", "Fight Club", 123, 250>, <"Tolkien", "The Hobbit", 300, 150>, <"Brown", "Da Vinci Code", 253, 300>, <"Rowling", "Harry Potter and the Philosopher's Stone", 112, 250>, <" Tolkien", "The Lord of the Rings", 543, 369>, <"Fitzgerald", "The Great Gatsby", 321, 281>, <"Salinger", "The Catcher in the Rye", 124, 1120>, <"Austen", "Pride and Prejudice", 300, 500>

.code
ORG 100h
start:
mov ax, @data 
mov DS, AX 

xor DI, DI 

mov CX, 10 
mov SI, OFFSET B 

iterate:
mov AX, [SI + Books.page_count] 
cmp AX, 200 
jbe not_more_than_200 

inc DI 

not_more_than_200:
add SI, TYPE Books 
loop iterate 


 mov ah, 4Ch 
INT 21h 

END start