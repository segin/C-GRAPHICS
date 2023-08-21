/* line.c */
/*draws a line between screen coordinates x1,y1 and x2,y2*/
/*using Bresenham's line algorithm*/

line (x1,y1,x2,y2,co)  /*arguments are the line coords. and color*/
int x1,y1,x2,y2,co;    /*declare arguments, all integers*/
{
    int xb,yb,xe,ye;   /*beginning and end line coords.*/
    int x,y;           /*coordinates used in plotting loop*/
    float dx,dy;       /*delta x and delta y*/
    int ic;            /*coordinate increment equals 1 or -1*/
    int dv;            /*decision variable*/
    int d1,d2;         /*decision variable increments*/

    dx=x2-x1;
    dx=(dx<0) ? -(dx) : dx;  /*absolute value of dx*/

    dy=y2-y1;
    dy=(dy<0) ? -(dy) : dy;  /*absolute value of dy*/

    /*test the slope for >1 or <=1 or vertical*/
    if (dx==0)
        goto inc_y;
    else {
        if (dy/dx>1) 
            goto inc_y;
        else
            goto inc_x;
    }

inc_x:
    /*draw the line, incrementing x by one each step and*/
    /*using the decision variable dv to choose the y increment*/
    d1=2*(dy-dx);      /*increment in dv if dv>=0*/
    d2=2*dy;           /*increment in dv if dv<0 */
    dv=2*dy-dx;        /*initial value for dv    */
    /*set the starting values so xb<xe*/
    if (x1<=x2) {
        xb=x1;
        xe=x2;
        yb=y1;
        ic=(y2>y1) ? 1 : -1;
    } else {
        xb=x2;
        xe=x1;
        yb=y2;
        ic=(y2>y1) ? -1 : 1;
    }

    /*draw the line*/
    /*loop increments x each step and dv decides if increment y*/
    pnt(xb,yb,co);    /*plot point at line beginning*/
    y=yb;
    for (x=xb+1;x<=xe;x=x+1){
        if(dv>=0) {
            dv=dv+d1;
             y=y+ic;
        } else {
            dv=dv+d2;
        }
        pnt(x,y,co);    /*plot the point*/
    }
    return;

inc_y:
    /*draw the line, incrementing y by one each step and*/
    /*using the decision variable dv to choose the x increment*/
    d1=2*(dx-dy);   /*increment in dv if dv>=0*/
    d2=2*dx;        /*increment in dv if dv<0 */
    dv=2*dx-dy;     /*initial value for dv    */
    /*set starting values so that yb<ye */
    if (y1<=y2) {
        yb=y1;
        ye=y2;
        xb=x1;
        ic=(x2>x1) ? 1 : -1;
    } else {
        yb=y2;
        ye=y1;
        xb=x2;
        ic=(x2>x1) ? -1 : 1;
    }

    /*draw the line*/
    /*loop increments y each time and dv decides if increment x*/
    pnt(xb,yb,co);    /*plot point at line beginning*/
    x=xb;
    for (y=yb+1;y<=ye;y=y+1) {
        if (dv>=0) {
            dv=dv+d1;
            x=x+ic;
        } else {
            dv=dv+d2;
        }
        pnt(x,y,co);    /*plot the point*/
    }
    return;
}
