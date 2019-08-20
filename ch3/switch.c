#include <stdio.h>
void escape(char s[],char t[]);
void unescape(char s[],char t[]);
int main(int argc, char const *argv[])
{
    char s[]="1234567890";
    char t[]="he\tllo\n\t";
    escape(s,t);
    printf("%s\n",s);
    char ss[]="123456789";
    unescape(ss,s);
    printf("%s\n",ss);
    return 0;
}

/*copy t to s and convert /t /n to literal*/ 
void escape(char s[],char t[]){
    int i,j;
    for(i=j=0;t[j]!='\0';j++){
        switch (t[j])
        {
        case '\n':
            s[i++]='\\';
            s[i++]='n';
            break;
        case '\t':
            s[i++]='\\';
            s[i++]='t';
            break;
        default:
            s[i++]=t[j];
            break;
        }
    }
    s[i]='\0';
}


void unescape(char s[],char t[]){
    int i,j;
    i=0;j=0;
    while(t[j]!='\0'){
        switch (t[j])
        {
        case '\\':
            switch (t[j+1])
            {
            case 'n':
                s[i++]='\n';
                break;
            case 't':
                s[i++]='\t';
                break;
            default:
                s[i++]='\\';
                s[i++]=t[j+1];
                break;
            }
            j+=2;
            break;
        default:
            s[i++]=t[j++];
            break;
        }
    }
    s[i]='\0';
}
