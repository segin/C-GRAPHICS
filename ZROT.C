/* zrot.c */
/*rotates point coordinates about the z-axis*/

#define xc 160    /*screen center x coordinate*/
#define yc 100    /*screen center y coordinate*/
#define zc 0     /*screen center z coordinate*/
#define pi 3.14159   /*used to convert degrees to radians*/

zrot(rz,np,xs,ys,zs)
float rz;               /*z-rotation in degrees*/
int np;                 /*number of points*/
int xs[],ys[],zs[];     /*point screen coordinates*/
{
    float sz,sinz();   /*declare sine function and sz=sinz(rz)*/
    float cz,cosz();   /*declare cosine function and cz=cosz(rz)*/
    float c[4][4];     /*coordinate transformation*/
    float xx,yy,zz;    /*temporary x,y,z coordinates*/
    int i;             /*loop counter*/

    /*convert degrees to radians*/
    rz=pi*(rz/180.);

    /*calculate cos(rz) and sin(rz) */
    cz=cosz(rz);
    sz=sinz(rz);

    /*setup transformation matrix*/
    c[1][1]=cz;
    c[1][2]=-sz;
    c[1][3]=0.;
    c[2][1]=sz;
    c[2][2]=cz;
    c[2][3]=0.;
    c[3][1]=0.;
    c[3][2]=0.;
    c[3][3]=1.;

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

float cosz(rz)
float rz;      /*angle in radians*/
{
    float cz;       /*cz=cos(rz) is returned to calling program*/

    /*use 4 term Taylor series approximation*/
    cz=1.-(rz*rz/2.)+(rz*rz*rz*rz/24.)-(rz*rz*rz*rz*rz*rz/720.);

    return(cz);
}

float sinz(rz)
float rz;       /*angle in radians*/
{
    float sz;       /*sz=sin(rz) is returned to calling program*/

    /*use 4 term Taylor series approximation*/
    sz=rz-(rz*rz*rz/6.)+(rz*rz*rz*rz*rz/120.)-
       (rz*rz*rz*rz*rz*rz*rz/5040.);

    return(sz);
}
