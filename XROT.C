/* xrot.c */
/*rotates point coordinates about the x-axis*/

#define xc 160    /*screen center x coordinate*/
#define yc 100    /*screen center y coordinate*/
#define zc 0     /*screen center z coordinate*/
#define pi 3.14159   /*used to convert degrees to radians*/

xrot(rx,np,xs,ys,zs)
float rx;               /*x-rotation in degrees*/
int np;                 /*number of points*/
int xs[],ys[],zs[];     /*point screen coordinates*/
{
    float sx,sinx();   /*declare sine function and sx=sinx(rx)*/
    float cx,cosx();   /*declare cosine function and cx=cosx(rx)*/
    float c[4][4];     /*coordinate transformation*/
    float xx,yy,zz;    /*temporary x,y,z coordinates*/
    int i;             /*loop counter*/

    /*convert degrees to radians*/
    rx=pi*(rx/180.);

    /*calculate cos(rx) and sin(rx) */
    cx=cosx(rx);
    sx=sinx(rx);

    /*setup transformation matrix*/
    c[1][1]=1.;
    c[1][2]=0.;
    c[1][3]=0.;
    c[2][1]=0.;
    c[2][2]=cx;
    c[2][3]=-sx;
    c[3][1]=0.;
    c[3][2]=sx;
    c[3][3]=cx;

    /*multiply coordinates by transformations*/
    for (i=1;i<=np;++i) {
        xx=c[1][1]*(xs[i]-xc) + c[1][2]*(ys[i]-yc) + c[1][3]*(zs[i]-zc);
        yy=c[2][1]*(xs[i]-xc) + c[2][2]*(ys[i]-yc) + c[2][3]*(zs[i]-zc);
        zz=c[3][1]*(xs[i]-xc) + c[3][2]*(ys[i]-yc) + c[3][3]*(zs[i]-zc);
        xs[i]=xx+xc;
        ys[i]=yy+yc;
        zs[i]=zz+zc;
    }

    return;
}

float cosx(rx)
float rx;      /*angle in radians*/
{
    float cx;       /*cx=cos(rx) is returned to calling program*/

    /*use 4 term Taylor series approximation*/
    cx=1.-(rx*rx/2.)+(rx*rx*rx*rx/24.)-(rx*rx*rx*rx*rx*rx/720.);

    return(cx);
}

float sinx(rx)
float rx;       /*angle in radians*/
{
    float sx;       /*sx=sin(rx) is returned to calling program*/

    /*use 4 term Taylor series approximation*/
    sx=rx-(rx*rx*rx/6.)+(rx*rx*rx*rx*rx/120.)-
       (rx*rx*rx*rx*rx*rx*rx/5040.);

    return(sx);
}
