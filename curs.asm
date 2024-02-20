.model small
.stack 100h

.data
; define struct "Drink"
; size of Drink = 60 bytes
Drink STRUC
drink_name db 20 DUP (?) ; 20 characters for drink name
main_ingredient db 20 DUP (?) ; 20 characters for main ingredient
ice_presence db ? ; 1 byte for ice presence
drink_volume dw ? ; 2 bytes for drink volume
Drink ENDS

; array of 7 Drink structures
D Drink <"Coke", "Cola", 1, 300>, <"Tea", "Tea Leaves", 1, 250>, <"Coffee", "Coffee Beans", 1, 200>, <"Lemonade", "Lemon", 1, 350>, <"Orange Juice", "Orange", 0, 400>, <"Milkshake", "Milk", 0, 500>, <"Water", "None", 0, 450>

.code
ORG 100h
start:
mov ax, @data ; set AX to data segment
mov DS, AX ; set DS to point to data segment

xor DI, DI ; null DI register, DI will store the count of drinks needing ice

; loop through each drink in the array
mov CX, 7 ; set CX to the number of drinks in the array
mov SI, OFFSET D ; set SI to point to the beginning of the array

iterate:
mov AL, [SI + Drink.ice_presence] ; load the ice presence flag of the current drink
cmp AL, 1 ; compare with 1 (indicating ice needed)
jne no_ice_needed ; jump if ice not needed for this drink

inc DI ; increment DI if ice is needed for this drink

no_ice_needed:
add SI, TYPE Drink ; move to the next drink in the array
loop iterate ; continue the loop until all drinks are checked

; Now, DI contains the count of drinks needing ice
mov ah, 4Ch
INT 21h ; you may want to use DI for further processing or output

END start