#include <stdio.h>

void printd(int n);
int main(int argc, char const *argv[])
{

    printd(1234);
    printf("\n");
    
    return 0;
}

void printd(int n){
    if(n<0){
        putchar('-');
        n=-n;
    }

    if(n/10)
        printd(n/10);
    putchar(n%10+'0');
}

/*itoa: convert integer n to s
void itoa(int n,char s[],int i){
    if(n<0){
        s[i]='-';
        n=-n;
    }
    if(n/10)
        itoa(n/10,s,);
    s[i]=n%10+'0';

}
*/

void reverse(char s[]){
    
}
