#include <stdio.h>


void strcat1(char* s,char* t);
int main(int argc, char const *argv[])
{
    char s[]="hello";
    char t[]="world";
    strcat1(s,t);
    printf("%s\n",s);
    return 0;
}


/*strcpy1: copy t to s;array version */
void strcpy1(char *s,char *t){
    int i;
    i=0;
    while((s[i]=t[i])!='\0')
        i++;
}

/* strcpy2: copy t to s; pointer version*/
void strcpy2(char *s,char *t){
    int i;
    i=0;
    while((*s=*t)!='\0'){
        s++;
        t++;
    }
}

/* strcyp3 :copy t to s;pointer version 2*/
void strcpy3(char *s,char *t){
    while((*s++ = *t++)!='\0')
        ;
    
    /* a more simple version
    while(*s++=*t++)
        ;
    */
}

/*array version*/
int strcmp1(char *s,char *t){
    int i;
    for(i=0;s[i]==t[i];i++){
        if(s[i]=='\0')
            return 0;
    }
    return s[i]-t[i];
}

/*pointer version*/
int strcmp2(char *s,char *t){
    for(;*s==*t;s++,t++){
        if(*s=='\0')
            return 0;
    }
    return *s - *t;
}

/*strcat : point version*/
void strcat1(char *s,char *t){
    for(;*s!='\0';s++)
        ;
    while(*s++=*t++)
        ;
}

/*strend: if t exist in s tail return 1 else 0*/
int strend(char *s,char *t){
    int ls,lt;

    for(ls=0;*(s+ls);++ls);
    for(lt=0;*(t+lt);++lt);
    if(ls>=lt){
        s+=ls - lt;
        while(*s++ = *t++){
            if(!*s)
                return 1;
        }
    }
    return 0;
}