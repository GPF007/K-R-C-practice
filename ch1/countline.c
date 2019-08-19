#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c,nl,ns,nt;
    nl=0;
    ns=0;
    nt=0;
    while((c=getchar())!=EOF){
        if(c=='\n')
            ++nl;
        else if(c=='\t')
            ++nt;
        else if (c==' ')
            ++ns;
    }
    printf("The line break:%d\n",nl);
    printf("The space is %d\n",ns);
    printf("The TAB is %d\n",nt);
    return 0;
}
