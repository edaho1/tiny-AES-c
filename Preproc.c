
#include "Prehandle.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        fprintf(stderr,"Must supply filename to read\n");
        exit(1);
    }

    //Load file into data structure
    int length = 0;
    int length2 = 0;
    char **CTR_128_intermediateval = loadfile(argv[1],&length);
    char **result = loadfile(argv[2],&length2);

    // display the first 100 lines to check
    // printf("CTR_128_intermediateVal length:%d\n",length);
    // for (int i = 0; i <5; i++)
    // {
    //     printf("%s\n",CTR_128_intermediateval[i]);
    // }
    // printf("result length:%d\n",length2);
    // for (int i = 0; i <length2; i++)
    // {
    //     printf("%s\n",result[i]);
    // }   
    
    // removing spaces and rearranging values
    char * newCTR = deblank(CTR_128_intermediateval[0]);
    uint8_t out[16];
    uint8_t* test =  hex_decode(newCTR, strlen(newCTR),out);

    // displaying first result to check if solution work
    // for (int i = 0; i < 16; i++)
    // {
    //     printf("%02x ",out[i]);
    // }
    // printf("\n");
    printf("%02x\n",Te4[0]);
    //static uint8_t count = bitcount(5);
    printf("%d\n",bitcount(255));
    // performing solution for entire data set
    // TO-DO: add sbox and hamming weight for AES. compute all 15-bit exhaustive search and save to file.
    
}

