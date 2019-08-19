#include <stdio.h>

int main()
{
    printf("EOF value:%d\n",EOF);
    int c;
    //c=getchar();
    while ((c=getchar())!=EOF)
    {
        putchar(c);
        //c=getchar();
    }

    
    
}