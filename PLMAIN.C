/* plmain.c */
/*calls function plot() to plot a 5 point pyramid*/
/*function pscale() is called first to do the preliminary scaling*/
/*link with: c plmain gmode pnt line pscale plot */

#define n 10     /*size of point and line arrays*/
main()
{
    int np;                     /*number of points*/
    float xp[n],yp[n],zp[n];    /*physical coordinates*/
    int xs[n],ys[n],zs[n];      /*screen coordinates*/
    int nl;                     /*number of lines*/
    int lb[n],le[n];            /*line beginning and end points*/

    gmode();    /*switch to graphics mode*/

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

    /*call pscale() to do the preliminary scaling*/
    pscale(np,xp,yp,zp,xs,ys,zs);

    /*call plot() to plot the scaled points*/
    plot(np,xs,ys,zs,nl,lb,le);

}
