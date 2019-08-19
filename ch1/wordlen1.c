#include <stdio.h>

#define OUT 0
#define IN 1

#define MAX_LEN 100

int main(int argc, char const *argv[])
{
    int c,i;
    int nwords[MAX_LEN];
    int len=0;
    int state=OUT;
    for(i=0;i<MAX_LEN;i++)
        nwords[i]=0;
    while ((c=getchar())!=EOF)
    {
        if(c==' ' || c=='\t' || c=='\n'){
            if(state==IN){
                state=OUT;
                ++nwords[len];
                len=0;
            }
        }else{
            state=IN;
            ++len;
        }
    }

    //print histogram horizen
    for(i=1;i<MAX_LEN;i++){
        if(nwords[i]==0)
            continue;
        printf("%2d:",i);
        int j;
        for(j=0;j<nwords[i];++j){
            printf("=");
        }
        printf("\n");
    }

    //print histogram verticle
    
    return 0;
}
