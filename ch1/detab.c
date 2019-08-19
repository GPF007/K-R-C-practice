#include <stdio.h>
#define TABINC 5
int main(int argc, char const *argv[])
{
    int c,i;
    int pos=1,nb=0;
    while ((c=getchar())!=EOF)
    {
        if(c=='\t'){
            nb=TABINC - (pos-1) %TABINC;
            while(nb>0){
                putchar(' ');
                pos++;
                nb--;
            }
        }else{
            if(c=='\n') pos=1;
            else pos++;
            putchar(c);
        }
        /* code */
    }
    
    
    return 0;
}

