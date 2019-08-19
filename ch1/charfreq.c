#include <stdio.h>
//display every char's frequency
#define MAX_CHAR 128+1
int main(int argc, char const *argv[])
{
    int array[MAX_CHAR];
    int i;
    int nc=0,c=0;
    for(i=0;i<MAX_CHAR;++i)
        array[i]=0;
    
    while((c=getchar())!=EOF){
        ++nc;
        ++array[c-'0'];
    }

    for(i=0;i<MAX_CHAR;i++){
        if(array[i]==0) continue;

        int j;
        printf("%c:",i+'0');
        for(j=0;j<array[i];j++){
            printf("=");
        }
        printf("\n");
    }

    

    /* code */
    return 0;
}
