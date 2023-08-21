/* yrot.c */
/*rotates point coordinates about the y-axis*/

#define xc 160    /*screen center x coordinate*/
#define yc 100    /*screen center y coordinate*/
#define zc 0     /*screen center z coordinate*/
#define pi 3.14159   /*used to convert degrees to radians*/

yrot(ry,np,xs,ys,zs)
float ry;               /*y-rotation in degrees*/
int np;                 /*number of points*/
int xs[],ys[],zs[];     /*point screen coordinates*/
{
    float sy,siny();   /*declare sine function and sy=siny(ry)*/
    float cy,cosy();   /*declare cosine function and cy=cosy(ry)*/
    float c[4][4];     /*coordinate transformation*/
    float xx,yy,zz;    /*temporarys*/
    int i;             /*loop counter*/

    /*convert degrees to radians*/
    ry=pi*(ry/180.);

    /*calculate cos(ry) and sin(ry) */
    cy=cosy(ry);
    sy=siny(ry);

    /*setup transformation matrix*/
    c[1][1]=cy;
    c[1][2]=0.;
    c[1][3]=sy;
    c[2][1]=0.;
    c[2][2]=1.;
    c[2][3]=0.;
    c[3][1]=-sy;
    c[3][2]=0.;
    c[3][3]=cy;

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

float cosy(ry)
float ry;      /*angle in radians*/
{
    float cy;       /*cy=cos(ry) is returned to calling program*/

    /*use 4 term Taylor series approximation*/
    cy=1.-(ry*ry/2.)+(ry*ry*ry*ry/24.)-(ry*ry*ry*ry*ry*ry/720.);

    return(cy);
}

float siny(ry)
float ry;       /*angle in radians*/
{
    float sy;       /*sy=sin(ry) is returned to calling program*/

    /*use 4 term Taylor series approximation*/
    sy=ry-(ry*ry*ry/6.)+(ry*ry*ry*ry*ry/120.)-
       (ry*ry*ry*ry*ry*ry*ry/5040.);

    return(sy);
}
