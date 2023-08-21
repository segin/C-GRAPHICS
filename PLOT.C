/* plot.c */
/*plots np points with screen coordinates xs,ys,zs*/
/*and draws nl lines with beginning points lb and  */
/*end points le */

plot(np,xs,ys,zs,nl,lb,le)
int np;               /*number of points*/
int xs[],ys[],zs[];   /*point x,y,z screen coordinates*/
int nl;               /*number of lines*/
int lb[],le[];        /*line beginning and end points*/
{
    int aa,bb;    /*line beg. and end points used in plotting loops*/
    int i;        /*loop counter*/
    int co;       /*color*/

    /*plot np points*/
    co=3;                 /*use color white*/
    for (i=1;i<=np;++i) {
        pnt(xs[i],ys[i],co);   /*call pnt function to plot point*/
    }

    /*draw nl lines*/
    co=3;
    for (i=1;i<=nl;++i) {
        aa=lb[i];          /*get line beginning point*/
        bb=le[i];          /*get line end point*/
        line (xs[aa],ys[aa],xs[bb],ys[bb],co);  /*draw the line*/
    }

    return;
}
