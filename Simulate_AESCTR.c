#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "Prehandle.h"


int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        fprintf(stderr,"Must supply filename to read\n");
        exit(1);
    }
    int len = 0;
    double ** Data =  loadhypos(argv[1], &len);
    printf("%d\n",len);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j< 1344; j++)
        {
            printf("%lf ", Data[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}