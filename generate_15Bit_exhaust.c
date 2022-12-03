#include "Prehandle.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define GUESS 1<<15
#define NR_OF_MEAS 10000

int main(int argc, char * argv[])
{
    uint8_t hypos[GUESS][NR_OF_MEAS];
    int g,t;
    uint8_t b=0,nonceguess=0,keyguess=0,counter=0;
    printf("I'M HERE!\n");
    for(g = 0; g < GUESS;g++)
    {
        b = (g>>14) & 0x1;
        printf("b:%02x\n",b);
        nonceguess = (g>>7) & 0x7F;
        keyguess = g & 0x7F;
        for(t = 0; t < NR_OF_MEAS;t++)
        {
            counter = (nonceguess + t) & 0xFF;
            //hypos[g][t] = bitcount(Te4[keyguess ^ counter ^ (b>>7)]);
            printf("%02x\n",bitcount(Te4[keyguess ^ counter ^ (b>>7)]));
        }
    }
    return 0;
}