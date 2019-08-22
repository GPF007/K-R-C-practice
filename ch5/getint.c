#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);
int getfloat(float *);

#define SIZE 100

int main(int argc, char const *argv[])
{
    int n,array[SIZE];
    /*
    for(n=0;n<SIZE && getint(&array[n])!=EOF;n++)
        ;
    int i;
    for(i=0;i<n;i++)
        printf("array[%d] = %d\n",i,array[i]);  
    printf("\n");
    */
    int i;
    float arr[SIZE];
    for(n=0;n<SIZE && getfloat(&arr[n])!=EOF;n++)
        ;
    for(i=0;i<n;i++)
        printf("arr[%d] = %f\n",i,arr[i]);  
    return 0;
}


/* getint: get next integer from input into *pn */
int getint(int *pn){
    int c,sign;

    while(isspace(c=getch()))/*skip white space*/
        ;
    
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
        ungetch(c);
        return 0;
    }
    sign=(c=='-')?-1:1;
    if(c=='+' || c=='-')
        c=getch();
    for(*pn=0;isdigit(c);c=getch())
        *pn=10 * *pn + (c-'0');
    *pn *=sign;
    if(c!=EOF)
        ungetch(c);
    return c;
}

/*getfloat:get next float from input */
int getfloat(float *pn){
    int c,sign;
    float power;
    while(isspace(c=getch()))
        ;
    if(!isdigit(c) && c!=EOF&&c!='+'&& c!='-' && c!='.'){
        ungetch(c);
        return 0;
    }
    sign=(c=='-')?-1:1;
    if(c=='+' || c=='-')
        c=getch();
    for(*pn=0.0;isdigit(c);c=getch())
        *pn=10.0 * *pn + (c-'0');
    if(c=='.')
        c=getch();
    for(power=1.0;isdigit(c);c=getch()){
        *pn=10.0 * *pn + (c-'0');
        power*=10;
    }
    *pn= sign * (*pn) / power;
    if(c!=EOF)
        ungetch(c);
    return c;
}


#define BUFSIZE 100
static char buf[BUFSIZE];
static int bufp=0;

int getch(void){
    return (bufp>0) ? buf[--bufp]:getchar();
}

void ungetch(int c){
    if(bufp>=BUFSIZE)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++]=c;
}