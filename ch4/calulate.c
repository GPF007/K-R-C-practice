#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

#define MAXVAL 100 //stack depth
int sp=0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int c);

/* reverse Poish calculator*/
int main(int argc, char const *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while((type=getop(s))!=EOF){
        switch (type)
        {
        case NUMBER:
           // printf("%s\n",s);
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break;
        case '*':
            push(pop()*pop());
            break;
        case '-':
            op2=pop();
            push(pop()-op2);
            break;
        case '/':
            op2=pop();
            if(op2!=0.0)
                push(pop() / op2);
            else
                printf("error:zero division\n");
            break;
        case '%':
            op2=pop();
            if(op2!=0.0)
                push((int)pop() % (int)op2);
            else
                printf("error:zero mod\n");
            break;
        case 
        case '\n':
            printf("\t%.8g\n",pop());
            break;
        default:
            printf("error: unknown command %s\n",s);
            break;
        }
    }

    return 0;
}

void push(double f){
    if (sp<MAXVAL)
        val[sp++]=f;
    else
        printf("error: stack full, can't push %g\n",f);
}

double pop(void){
    if(sp>0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}
/*print the top element*/
void top(void){
    if(sp>0)
        printf("%g\n",val[sp-1]);
    else
        printf("error: stack empty\n");
}

/*getopt: get next char or numeric operand*/
int getop(char s[]){
    int i,c;
    while((s[0]=c=getch())==' '|| c=='\t')
        ;
    s[1]='\0';
    if(!isdigit(c) && c!='.')
        return c;
    i=0;
    
    if(isdigit(c)){
        while(isdigit(s[++i]=c=getch()))
            ;
    }
    if(c=='.')
        while(isdigit(s[++i]=c=getch()))
            ;
    s[i]='\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;

int getch(void){
    return (bufp>0) ? buf[--bufp]:getchar();
}

void ungetch(int c){
    if(bufp>=BUFSIZE)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++]=c;
}