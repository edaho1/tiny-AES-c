#include "Prehandle.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

char ** loadfile(char * filename, int * len)
{
    FILE *fp = fopen(filename,"r");
    if(!fp)
    {
        fprintf(stderr,"Can't open %s for reading\n",filename);
        return NULL;
    }

    int arrlen = STEPSIZE;
    // Allocate space for 100 char pointers
    char ** lines = (char **) malloc(arrlen*sizeof(char *));

    char buf[1000];
    int i = 0;
    while(fgets(buf,1000,fp))
    {
        if(i == arrlen)
        {
            arrlen += STEPSIZE;
            char ** newlines = realloc(lines,arrlen*sizeof(char *));
            if (!newlines)
            {
                fprintf(stderr,"can't realloc\n");
                exit(1);
            }
            lines = newlines;
        }
        // trim off newline char
        buf[strlen(buf)-1] = '\0';

        // Get length of buffer
        int slen = strlen(buf);
        char * str  = (char *)malloc((slen+1)*sizeof(char));

        //copy string from buf to str
        strcpy(str,buf);

        // attach str to data structure
        lines[i] = str;

        i++;

    }
    *len = i; // Set the length of the array of char pointers
    return lines;
}

char* deblank(char* input)                                         
{
    int i,j;
    char *output=input;
    for (i = 0, j = 0; i<strlen(input); i++,j++)          
    {
        if (input[i]!=' ')                           
            output[j]=input[i];                     
        else
            j--;                                     
    }
    output[j]=0;
    return output;
}


uint8_t* hex_decode(const char *in, size_t len,uint8_t *out)
{
        unsigned int i, t, hn, ln;

        for (t = 0,i = 0; i < len; i+=2,++t) {

                hn = in[i] > '9' ? (in[i]|32) - 'a' + 10 : in[i] - '0';
                ln = in[i+1] > '9' ? (in[i+1]|32) - 'a' + 10 : in[i+1] - '0';

                out[t] = (hn << 4 ) | ln;
        }

        return out;
}

uint8_t bitcount (uint8_t n)
{
    unsigned count = 0;
    while (n) 
    {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

