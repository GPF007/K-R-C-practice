#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[],int maxline);
void copy(char to[],char from[]);
void reverse(char s[],int len);

int main(int argc, char const *argv[])
{
    int len,max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max=0;
    while((len=getline2(line,MAXLINE))>0){
        if (len>max){
            max=len;
            copy(longest,line);
        }
    }
    if(max > 0){
        printf("origin:%s",longest);
        reverse(longest,max);
        printf("length:%d\n",max);
        printf("reversed:%s",longest); 
    }

    return 0;
}
/*getline: read aline into s,return length*/
int getline2(char s[],int lim){
    int c,i;
    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i]=c;
    if(c=='\n'){
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    return i;
}

/*copy: form -> to*/
void copy(char to[],char from[]){
    int i=0;

    while ((to[i]=from[i])!='\0')
    {
        ++i;
    }
}

void reverse(char s[],int len){
    int i,j;
    char tmp;
    for(i=0,j=len-2;i<j;++i,--j){
      //  printf("s[%d]=%c, s[%d]=%c\n",i,s[i],j,s[j]);
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
    //printf("%s\n",s);
}
