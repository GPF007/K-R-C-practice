#include <stdio.h>

void squeeze(char s[],int c);
void strcat1(char s[],char t[]);
void squeeze2(char s[],char t[]);
int any(char s1[],char s2[]);
int main(int argc, char const *argv[])
{
    char s1[]="asdasd";
    squeeze(s1,'a');

    printf("test squeeze:squeeze(asdasd,a):%s\n",s1);
    char s2[]="prefix";
    char s3[]="suffix";
    strcat1(s2,s3);
    printf("test strcat:%s\n",s2);

    printf("test squeeze2:\n");
    char s4[]="qwerqwrddd";
    squeeze2(s4,"qw");
    printf("squeeze2(qwerqwrddd,qw): %s\n",s4);
    printf("any(asdf,dqwe)=%d\n",any("asdf","dqwe"));
    
    return 0;
}
/* squeeze: deleter all c from s*/
void squeeze(char s[],int c){
    int i,j;
    for(i=j=0;s[i]!='\0';i++){
        if(s[i]!=c)
            s[j++]=s[i];
    }
    s[j]='\0';
}

void squeeze2(char s[],char t[]){
    int i,j,k;
    //i=j=k=0;
    for(i=j=0;s[i]!='\0';i++){
        for(k=0;t[k]!='\0';k++){
            //printf("s[%d]=%c;t[%d]=%c\n",i,s[i],k,t[k]);
            if(s[i]==t[k])
                break;
        }
        if(t[k]=='\0'){
          s[j++]=s[i];  
        }
    }
    s[j]='\0';
}

/*strcat: concatenate t to end of s; s must be big enough*/
void strcat1(char s[],char t[]){
    int i,j;
    i=j=0;
    while(s[i]!='\0')
        i++;
    while((s[i++]=t[j++])!='\0')
    ;

}

int any(char s1[],char s2[]){
    int i,j;
    for(i=0;s1[i]!='\0';i++){
        for(j=0;s2[j]!='\0';j++){
            if(s1[i]==s2[j])
                return i;
        }
    }

    return -1;
}
