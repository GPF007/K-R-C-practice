#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 1000
#define MAXLINES 5000
int getline1(char s[],int lim);
int readlines(char *lineptr[],int maxlines);
int main(int argc, char const *argv[])
{
    char *lineptr[MAXLINES];
    int number;
    int nes=0;
    int c;
     while(--argc > 0 &&(*++argv)[0] == '-'){
        while(c=*++argv[0]){
            if(isdigit(c)){
                nes=nes*10+(c-'0');
            }else
                break;
        }
    }
    number=(nes==0)?10:nes;

    int n=readlines(lineptr,MAXLINES);
    int i;
    for(i=n-number;i<n;i++){
        printf("%d:%s",i,lineptr[i]);
    }
        //printf("%s",*lineptr);
    return 0;
}

int readlines(char *lineptr[],int maxlines){
    int len,nlines;
    char *p, line[MAXLEN];
    nlines=0;

    while ((len=getline1(line,MAXLEN))>0)
    {
        if(nlines >=maxlines || (p=(char *)malloc(len*sizeof(char))) == NULL)
            return -1;
        else{
            line[len]='\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
        }
    }
    return nlines;
    
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