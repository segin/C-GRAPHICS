; PROGRAM GMODE.ASM
;gmode() switches display output to the IBM color/graphics card and
;puts the c/g card into 320x200 color graphics mode.

;GMODE.OBJ must be linked with C programs that make calls to 
;function gmode() .

;the code segment in GMODE is called prog and it is grouped in
;group pgroup so it will link into the same area of memory 
;as our C programs.
;similarly, the stack segment is grouped in data group dgroup so
;the stack will be in the same area of memory as the stack
;setup by C programs.

pgroup   group   prog
dgroup   group   stack

;******************************************************************
;define the stack segment.
;classify as 'data' so linked contiguous with the C stack.
stack      segment  stack 'data'
    db  200 dup (?)  ;reserve 200 bytes of stack space
stack      ends
;***********************************************************
;define data segment so we can get the output flag at address 410h
;flag controls whether output goes to monochrome screen or c/g card
display_data   segment at 40h
               org 10h
flag   dw   ?
display_data   ends
;*******************************************************************
;define the program segment. 
;public 'prog' will concatenate the segment with C programs.
prog      segment  byte  public 'prog'
          public  gmode

     assume cs:prog
     assume ds:display_data

;-------------------------------------------------------------------
gmode  proc  near
       ;first save bp and ds on stack so we can restore before return
       push bp
       push ds

       ;put stack pointer in bp
       mov bp,sp

;now change value at 410h to switch output to c/g card
;first set the data segment so we can access variable flag at 410h
       mov ax,display_data
       mov ds,ax

       mov ax,flag         ;get current value at 410h
       and ax,11001111b  ;zero bits 4 and 5 w/o affecting the rest
       or  ax,00100000b  ;set output to color graphics card
       mov flag,ax      ;put the new value back into flag 


;call DOS to set graphics card for 320x200 graphics
       mov al,4          ;for 320x200 graphics
       mov ah,0          ;set mode function
       int 10h           ;call ROM BIOS video routine

       mov sp,bp    ;reset stack pointer
       pop ds       ;restore calling program's ds
       pop bp       ;restore calling program's bp
       ret           ;return to calling program
gmode  endp

prog     ends
;********************************************************************

       end                 ;end assembly
