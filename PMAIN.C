/* pmain.c */
/*calls the pnt() function to plot a point at center of screen*/
/*link with: c pmain gmode pnt */

main()
{
    int x,y,c;       /*declare x,y and c as integer variables*/

    gmode();         /*switch to graphics mode*/

    x=160;           /*set x plotting coordinate*/
    y=100;           /*set y plotting coordinate*/
    c=3;             /*set the point's color to white*/
    pnt(x,y,c);      /*call function pnt() to plot the point*/

}
