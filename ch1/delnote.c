#include <stdio.h>


#define PROGRAM 0
#define COMMIT 1
#define QUOTE 2
#define SLASH 3
#define STAR 4
#define LITERAL 5

int main(int argc, char const *argv[])
{
    int c,state;
    char quote;
    state=PROGRAM;
    while ((c=getchar())!=EOF)
    {
        if(state == PROGRAM){
            if(c=='/')
                state=SLASH;
            else{
                if(c=='"' || c=='\''){
                    state=QUOTE;
                    quote=c;
                }
                putchar(c);              
            }
        }else if(state==COMMIT){
            if(c=='*')
                state=STAR;
        }else if(state==QUOTE){
            if(c=='\\')
                state=LITERAL;
            else if(c==quote)
                state=PROGRAM;
            putchar(c);
        }else if(state==SLASH){
            if(c=='*')
                state=COMMIT;
            else if(c=='"' || c=='\''){
                state=QUOTE;
                quote=c;
            }else{
                state=PROGRAM;
                putchar('/');
                putchar(c);
            }
        }else if(state==STAR){
            if(c=='/')
                state=PROGRAM;
            else
                state=COMMIT;
        }else if(state==LITERAL){
            putchar(c);
            state=QUOTE;
        }
    }
    
    return 0;
}
