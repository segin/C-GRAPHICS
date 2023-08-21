;  PROGRAM PNT.ASM
;pnt(xs,ys,co) uses ROM BIOS video interrupt to plot a point at
;screen coordinates xs,ys with color co (color can be black, co=0)

;PNT.OBJ must be linked with C programs that make calls to 
;function pnt(xs,ys,co) .

;the code segment in PNT is called prog and it is grouped in
;group pgroup so it will link into the same area of memory as
;our C programs.
;similarly, the stack segment is grouped in data group dgroup so
;the stack will be in the same area of memory as the stack
;setup by our C program.

pgroup   group   prog
dgroup   group   stack


;******************************************************************
;define stack segment
stack      segment  stack  'data'
    db  200  dup (?)  ;reserve 200 bytes of stack space
stack      ends
;********************************************************************
;define data segment
;the arguments are gotten off the stack and saved in xs,ys,co
coord_data   segment
xs    dw   ?
ys    dw   ?
co    dw   ?
coord_data    ends
;*******************************************************************
;define program segment
prog      segment  byte  public 'prog'
          public  pnt

     assume cs:prog
     assume ds:coord_data

;-------------------------------------------------------------------
pnt    proc  near
       ;first save caller's bp and ds so can restore before return
       push bp
       push ds

       ;now save the stack pointer in bp so we can use it to
       ;find the arguments on the stack
       mov bp,sp

       ;set the data segment register to coord_data
       mov ax,coord_data
       mov ds,ax
       ;get the arguments off the stack
       mov ax,[bp+6]
       mov xs,ax
       mov ax,[bp+8]
       mov ys,ax
       mov ax,[bp+10]
       mov co,ax

       ;call the ROM BIOS video routine to plot xs,ys
       mov ax,co      ;set the color
       mov ah,12d     ;set point function
       mov cx,xs      ;set x plotting coordinate
       mov dx,ys      ;set y plotting coordinate
       int 10h        ;jump to video ROM routine

       ;reset stack pointer and restore calling program's ds and bp
       mov sp,bp
       pop ds
       pop bp

       ;finally, return to calling program and pop the old values
       ;of xs,ys and co off the stack so it doesn't keep growing.
       ret 6
pnt    endp

prog     ends
;********************************************************************

       end                 ;end assembly
