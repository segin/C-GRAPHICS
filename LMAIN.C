/* lmain.c */
/*calls function line() to draw a diagonal line across the screen*/
/*link with: c lmain gmode pnt line */

main()
{
    int x1,y1;   /*declare line beginning coordinates*/
    int x2,y2;   /*declare line end coordinates*/
    int co;      /*declare line color*/

    gmode();     /*switch to graphics mode*/

    x1=0;        /*starting x coordinate*/
    y1=0;        /*starting y coordinate*/
    x2=319;      /*end x coordinate*/
    y2=199;      /*end y coordinate*/
    co=3;        /*color=white*/

    line(x1,y1,x2,y2,co);  /*plot the line*/

}
