#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


int getline1(char s[],int lim);
int strindex(char s[],char t[]);

char pattern[]="while";
/*find all lines matching pattern*/
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    int found=0;
    while(getline1(line,MAXLINE)>0){
        if(strindex(line,pattern)>=0){
            printf("%s",line);
            found++;
        }
    }
    
    return 0;
}

/*getline: getline into s, return length*/
int getline1(char s[],int lim){
    int c,i;
    i=0;

    while(--lim>0 &&(c=getchar())!=EOF && c!='\n')
        s[i++]=c;
    if(c=='\n')
        s[i++]=c;
    s[i]='\0';

    return i;
}

/*strindex: return index of t in s, -1 if none*/
int strindex(char s[],char t[]){
    int i,j,k;
    for(i=0;s[i]!='\0';++i){
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k]=='\0')
            return i;
    }
    return -1;
}

/*strindex2:return index of t in s(from right begin)*/
int strindex2(char s[],char t[]){
    int i,j,k;
    for(i=strlen(s)-1;i>=0;i--){
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k]=='\0')
            return i;
    }
}