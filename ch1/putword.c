#include <stdio.h>

#define IN 1 
#define OUT 0

/*print one word one line*/
int main(int argc, char const *argv[])
{
    int c,nl,nw,nc,state;
    state=OUT;
    nl=nw=nc=0;
    while((c=getchar())!=EOF){
        ++nc;
        if(c=='\n')
            ++nl;
        if(c==' '||c=='\n' || c=='\t'){
            if(state==IN){
                putchar('\n');
            }
            state=OUT;
        }else{
            if(state==OUT){
                state=IN;
                ++nw;
            }
            putchar(c);
        }
    }

    
    return 0;
}
