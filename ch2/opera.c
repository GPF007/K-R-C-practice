#include <stdio.h>
int bitcount(unsigned x);
int main(int argc, char const *argv[])
{

    int a=10;
    printf("bitcount(%)= %d\n",a,bitcount(a));
    
    return 0;
}

/*bitcount: count 1 bits in x*/
int bitcount(unsigned x){
    int b;
    for(b=0;x!=0;x>>=1){
        if (x & 1)
            b++;
    }
    return b;
}
