#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    
    return 0;
}
/* trim: remove trailing blanks,tabs new lines*/
int trim(char s[]){
    int n;

    for(n=strlen(s)-1;n>=0;n--){
        if(s[n]!=' ' && s[n]!='\t' && s[n]!='\n')
            break;
        s[n+1]='\0';
        return n;
    }
}