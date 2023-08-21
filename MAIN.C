/* main.c */
/*uses all the C-graphics functions.*/
/*operates on the 5 point pyramid*/
/*link with:c main gmode pnt line pscale plot scale trans xrot yrot zrot        */

#define n 10  /*size of point arrays*/

main()
{
    int np=0;                /*number of points*/
    float xp[n],yp[n],zp[n]; /*physical coordinates*/
    int xs[n],ys[n],zs[n];   /*scaled screen coordinates*/
    int nl=0;                /*number of lines*/
    int lb[n],le[n];         /*line beg. and end points*/
    float sf,pscale();       /*pscale returns sf */
    float rx,ry,rz;           /* x,y,z rotations in degrees*/
    int tx,ty,tz;             /*x,y,z translations*/
    int i;                    /*loop counter*/

    gmode();   /*switch to graphics mode*/

    /*define pyramid points*/
    np=5;
    xp[1]=0.;
    yp[1]=0.;
    zp[1]=0.;
    xp[2]=1000.;
    yp[2]=0.;
    zp[2]=0.;
    xp[3]=1000.;
    yp[3]=0.;
    zp[3]=2000.;
    xp[4]=0.;
    yp[4]=0.;
    zp[4]=2000.;
    xp[5]=500.;
    yp[5]=2000.;
    zp[5]=1000.;

    /*define pyramid lines*/
    nl=8;
    lb[1]=1;
    le[1]=2;
    lb[2]=2;
    le[2]=3;
    lb[3]=3;
    le[3]=4;
    lb[4]=4;
    le[4]=1;
    lb[5]=1;
    le[5]=5;
    lb[6]=2;
    le[6]=5;
    lb[7]=3;
    le[7]=5;
    lb[8]=4;
    le[8]=5;

    /*call function pscale() to scale and center xp,yp,zp*/
    sf=pscale(np,xp,yp,zp,xs,ys,zs);

    /*call function plot() to plot the pyramid*/
    plot(np,xs,ys,zs,nl,lb,le);

    /*30000 count pause*/
    for (i=1;i<=30000;++i) {
    }

    /*call function scale() to scale the pyramid by .5*/
    sf=.5;
    scale(sf,np,xs,ys,zs);

    /*call gmode() and plot() to re-plot the pyramid*/
    gmode();
    plot(np,xs,ys,zs,nl,lb,le);

    /*30000 count pause*/
    for (i=0;i<=30000;++i) {
    }

    /*call function xrot() to rotate 30 degrees about the x-axis*/
    rx=30.;
    xrot(rx,np,xs,ys,zs);

    /*call gmode() and plot() to re-plot the pyramid*/
    gmode();
    plot(np,xs,ys,zs,nl,lb,le);

    /*30000 count pause*/
    for (i=0;i<=30000;++i) {
    }

    /*call function yrot() to rotate 40 degrees about the y-axis*/
    ry=40.;
    yrot(ry,np,xs,ys,zs);

    /*call gmode() and plot() to re-plot the pyramid*/
    gmode();
    plot(np,xs,ys,zs,nl,lb,le);

    /*30000 count pause*/
    for (i=0;i<=30000;++i) {
    }

    /*call function zrot() to rotate 50 degrees about the z-axis*/
    rz=50.;
    zrot(rz,np,xs,ys,zs);

    /*call gmode() and plot() to re-plot the pyramid*/
    gmode();
    plot(np,xs,ys,zs,nl,lb,le);

    /*30000 count pause*/
    for (i=0;i<=30000;++i) {
    }

    /*call function trans() to translate 100 pixels along x-axis*/
    tx=100;
    ty=0;
    tz=0;
    trans(tx,ty,tz,np,xs,ys,zs);

    /*call gmode() and plot() to re-plot the pyramid*/
    gmode();
    plot(np,xs,ys,zs,nl,lb,le);

    /*30000 count pause*/
    for (i=0;i<=30000;++i) {
    }

}
