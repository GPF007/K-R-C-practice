#include <stdio.h>

/*
  copy the input to output
  replace multiple spaces with one space
  replace \t \b \\ with something can display

*/

int main(int argc, char const *argv[])
{
    int c;
    int ns=0;
    while((c=getchar())!=EOF){
        if(c==' '){
            if(ns==0)
                putchar(c);
            ++ns;
        }else{
            ns=0;
            if(c=='\t')
                printf("\\t");
            else if(c=='\b')
                printf("\\b");
            else if(c=='\\')
                printf("\\\\");
            else
                putchar(c);
        } 
    }
    return 0;
}
