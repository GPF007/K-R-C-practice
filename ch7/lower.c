#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{

    printf("argv[0]:%s\n",argv[0]);
    int c;
    while((c=getchar())!=EOF){
        putchar(tolower(c));
    }
    return 0;
}
