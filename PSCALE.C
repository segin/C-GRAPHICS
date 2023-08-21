/* pscale.c */
/*scales physical coordinates to fit the screen */
/*and returns the scale factor.*/
/*also centers the points.*/
/*xp,yp,zp are the real physical coordinates*/
/*xs,ys,zs are the scaled and centered screen coordinates*/
/*sf is the scale factor - returned to calling program*/

#define sm 150    /*minimum screen plotting dimension*/
#define xc 160    /*screen center x coordinate*/
#define yc 100    /*screen center y coordinate*/
#define zc 0      /*screen center z coordinate*/

float pscale(np,xp,yp,zp,xs,ys,zs)
float xp[],yp[],zp[];   /*physical coordinates*/
int xs[],ys[],zs[];     /*scaled screen coordinates*/
int np;                 /*number of points*/
{
    float xm,ym,zm;  /*largest x,y,z dimensions*/
    float dm;        /*largest of xm,ym,zm*/
    float sf;        /*scale factor*/
    int xo,yo,zo;    /*geometric center of points*/
    float dd;        /*temporary*/
    int i,j;         /*loop variables*/

    /*find largest dimensions between any two points*/
    /*and find xo,yo,zo the geometric center of the points*/
    xo=0;
    yo=0;
    zo=0;
    xm=0.;
    ym=0.;
    zm=0.;
    for (i=1;i<=np;++i) {
        for (j=i+1;j<=np;++j) {
            dd=xp[j]-xp[i];
            dd=(dd<0) ? -dd : dd;
            if (dd>xm) {
                xm=dd;
                xo=(xp[j]+xp[i])/2;
            } else {
            }

            dd=yp[j]-yp[i];
            dd=(dd<0) ? -dd : dd;
            if (dd>ym) {
                ym=dd;
                yo=(yp[j]+yp[i])/2;
             } else {
             }

             dd=zp[j]-zp[i];
             dd=(dd<0) ? -dd : dd;
             if (dd>zm) {
                 zm=dd;
                 zo=(zp[j]+zp[i])/2;
              } else {
              }

        }
    }

    /*find dm, largest of xm,ym,zm*/
    dm=(xm>ym) ? xm : ym;
    dm=(dm>zm) ? dm : zm;

    /*scale factor=smallest screen dimension divided by dm*/
    sf=sm/dm;

    /*use sf to calculate the scaled screen coords. xs,ys,zs*/
    for (i=1;i<=np;++i) {
        xs[i]=sf*xp[i];
        ys[i]=sf*yp[i];
        zs[i]=sf*zp[i];
    }

    /*apply scale factor to xo,yo,zo*/
    xo=sf*xo;
    yo=sf*yo;
    zo=sf*zo;

    /*subtract xo,yo,zo to center the points at xc,yc,zc*/
    for (i=1;i<=np;++i) {
        xs[i]=xs[i]-(xo-xc);
        ys[i]=ys[i]-(yo-yc);
        zs[i]=zs[i]-(zo-zc);
    }

    return(sf);
}
