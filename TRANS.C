/* trans.c */
/*translates point screen coordinates xs,ys,zs by */
/*amounts tx,ty,tz */

trans(tx,ty,tz,np,xs,ys,zs)
int tx,ty,tz;          /*x,y,z translations in screen coordinates*/
int np;                /*number of points*/
int xs[],ys[],zs[];    /*point screen coordinates*/
{
    int i;   /*loop counter*/

    /*loop through points adding in translations*/
    for (i=1;i<=np;++i) {
        xs[i]=xs[i]+tx;
        ys[i]=ys[i]+ty;
        zs[i]=zs[i]+tz;
    }

    return;
}
