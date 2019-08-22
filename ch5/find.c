#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int getline1(char s[],int lim);
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c,except=0,number=0,found=0;

    while(--argc > 0 &&(*++argv)[0] == '-'){
        while(c=*++argv[0]){
            switch (c)
            {
            case 'x':
                except=1;
                break;
            case 'n':
                number=1;
                break;
            default:
                printf("find: illegal option %c\n",c);
                argc=0;
                found=-1;
                break;
            }
        }
    }

    if(argc!=1)
        printf("Usage:find -x -n pattern\n");
    else{
        while(getline1(line,MAXLINE)>0){
            lineno++;
            if((strstr(line,*argv)!=NULL)!=except){
                if(number)
                    printf("%ld:",lineno);
                printf("%s",line);
                found++;
            }
        }
    }
    /*

    if(argc!=2)
        printf("Usage: find pattern\n");
    else{
        while(getline1(line,MAXLINE)>0){
            if(strstr(line,argv[1])!=NULL){
                printf("%s",line);
                found++;
            }
        }
    }
    */
    
    return found;
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
