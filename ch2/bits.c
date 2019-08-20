#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

/*getbits: get n bits from position p*/
unsigned getbits(unsigned x,int p,int n){
    return (x>>(p+1-n)) & ~(~0 << n);
}
/*setbits: set x [p,p+n] bits to y[n:] */
unsigned setbits(unsigned x,int p,int n,unsigned y){
    return (~(~0 << n) & y << (p+1-n)) | x; 
}

unsigned invert(unsigned x,int p,int n){
    return ((~0 << (p+1-n)) & ~(~0 << p)) ^ x;
}

unsigned rightrot(unsigned x,int n){
    while(n>0){
        if(x&1)
            x=(x>>1)| ~(~0U >>1);
        else
            x=x>>1
        --n;
    }
    return x;
}