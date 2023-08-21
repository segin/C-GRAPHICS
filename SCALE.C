/* scale.c */
/*scales point screen coordinates by scale factor sf */

#define xc 160      /*screen center x coordinate*/
#define yc 100      /*screen center y coordinate*/
#define zc 0        /*screen center z coordinate*/

scale(sf,np,xs,ys,zs)
float sf;           /*scale factor*/
int np;             /*number of points*/
int xs[],ys[],zs[]; /*point screen coordinates,should already
                      be prescaled*/
{
    int i;     /*loop counter*/

    /*loop through points multiplying by new scale factor*/
    for (i=1;i<=np;++i) {
        xs[i]=sf*(xs[i]-xc) + xc;
        ys[i]=sf*(ys[i]-yc) + yc;
        zs[i]=sf*(zs[i]-zc) + zc;
    }

    return;
}
