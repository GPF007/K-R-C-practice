#include <stdio.h>

int strlenn(char *);

int main(int argc, char const *argv[])
{
    char s[]="Hello world!";
    printf("strlen(%s) = %d\n",s,strlenn(s));
    return 0;
}

/* strlenn: return length of string */
int strlenn(char *s){
    int n;
    for(n=0;*s!='\0';s++)
        n++;
    return n;
}
