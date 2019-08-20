#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int atoi(char s[]);
void expand(char s[],char t[]);
void reverse(char s[]);
void itoa(int n,char s[]);
void itob(int n,char s[],int b);

int main(int argc, char const *argv[])
{
    char s[]="-30";
    printf("atoi(%s)=%d\n",s,atoi(s));
    char s1[]="-a-b-c a-z 0-9";
    char s2[100];
    expand(s1,s2);
    printf("%s\n",s2);
    char s3[100];
    itob(100,s3,16);
    printf("%s\n",s3);
    return 0;
}

/*convert s to integer;*/
int atoi(char s[]){
    int i,n,sign;

    for(i=0;isspace(s[i]);++i)
        ;
    sign=(s[i]=='-')?-1:1;
    if(s[i]=='+' || s[i]=='-')
        i++;
    for(n=0;isdigit(s[i]);i++)
        n=10*n+(s[i]-'0');
    return sign * n;

}

/*itoa convert n to chars in s*/
void itoa(int n,char s[]){
    int i,sign;
    if((sign=n)<0)
        n=-n;
    i=0;
    do{
        s[i++]=n%10+'0';
    }while((n/=10)>0);
    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    reverse(s);
}

/*itoa2 convert n to chars in s;w is the minist width of s*/
void itoa2(int n,char s[],int w){
    int i,sign;
    if((sign=n)<0)
        n=-n;
    i=0;
    do{
        s[i++]=n%10+'0';
    }while((n/=10)>0);
    if(sign<0)
        s[i++]='-';
    while(i<w){
        s[i++]=' ';
    }
    s[i]='\0';
    reverse(s);
}

/*itob: conevert n to chars s base b*/
void itob(int n,char s[],int b){
    int i,sign;
    if((sign=n)<0)
        n=-n;
    i=0;
    do{
        s[i++]= n%b+'0';
    }while(n/=b);
    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    reverse(s);
}

/*expand: expand s [a-z] to t of abc...z*/
void expand(char s[],char t[]){
    int i,j,k;
    for(i=j=0;s[i]=='-';++i){
        t[j++]='-';
    }
    while(s[i]!='\0'){
        if(s[i]=='-'){
            if(islower(s[i+1]) || isupper(s[i+1]) || isdigit(s[i+1])){
                for(k=1;k<(s[i+1]-s[i-1]);k++)
                    t[j++]=k+s[i-1];
            }else
                t[j++]=s[i];
        }else 
            t[j++]=s[i];
        
        ++i;
    }
    t[j]='\0';

}


void reverse(char s[]){
    int i,j;
    int c;
    for(i=0,j=strlen(s)-1;i<j;++i,--j){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}