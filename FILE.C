/* file.c */
/*saves point and line data on disk with filename PYRAMID*/

#include "stdio.h"    /*read your c-compilers standard i/o info.*/
#define fn "pyramid"  /*filename*/

file(np,xp,yp,zp,nl,lb,le)
int np;                 /*number of points*/
float xp[],yp[],zp[];   /*point coordinates*/
int nl;                 /*number of lines*/
int lb[],le[];          /*line beginning and end points*/

{
    FILE *fp;            /*pointer fp points to data structure FILE*/
    FILE *fopen();       /*and function fopen() returns pointer fp*/
    int i,c;             /*temporary integers*/

    /*open the file for writing data*/
    fp=fopen(fn,"w");

    /*write the point data*/
    fprintf(fp,"%5d \n",np);
    for (i=1;i<=np;++i) {
        fprintf(fp,"%13.6f \n",xp[i]);     /*write x coordinate*/
        fprintf(fp,"%13.6f \n",yp[i]);     /*write y coordinate*/
        fprintf(fp,"%13.6f \n",zp[i]);     /*write z coordinate*/
    }

    /*write the line data*/
    fprintf(fp,"%5d \n",nl);
    for (i=1;i<=nl;++i) {
        fprintf(fp,"%5d \n",lb[i]);      /*write line beg. point*/
        fprintf(fp,"%5d \n",le[i]);      /*write line end poine*/
    }

    /*close the file before returning*/
    fclose(fp);

    return;
}
