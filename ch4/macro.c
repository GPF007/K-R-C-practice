#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n",expr)
#define paste(front,back) front ## back

#define SWAP(t,x,y) t tmp;tmp=x;x=y;y=tmp;

int main(int argc, char const *argv[])
{
    double x=4.0,y=3.0;
    dprint(x/y);
    int paste(name,1) =0;
    printf("%d\n",name1);
    SWAP(int,x,y)
    dprint(x);
    dprint(y);
    /* code */
    return 0;
}
