#include <stdio.h>

int atoi(char s[]);
int lower(int c);
int htoi(char s[]);
int lower2(int c);
int main(int argc, char const *argv[])
{
    printf("atoi(123):%d\n",atoi("123"));
    printf("htoi(0x64):%d %x\n",htoi("0x64"),htoi("0x64"));
    return 0;
}

/*atoi:convert s to integer*/
int atoi(char s[]){
    int i,n;

    n=0;
    for(i=0;s[i]>='0' && s[i]<='9';++i)
        n=10*n+(s[i]-'0');
    return n;
}
/* lower: convert c to lower case */
int lower(int c){
    if(c>='A' && c<='Z')
        return c+'a'-'A';
    else
        return c;
}

int lower2(int c){
    return (c>='A' && c<='Z')? c+'a'-'A' : c;
}


/*htoi: convert s to integer(base16)*/
int htoi(char s[]){
    int i,n;
    n=0;
    for(i=2;s[i]>='0'&&s[i]<='9' || s[i]>='a'&&s[i]<='f' || s[i]>='A'&&s[i]<='F';++i)
    {
        if(s[i]>='0'&& s[i]<='9')
            n=16*n+(s[i]-'0');
        else if(s[i]>='a'&&s[i]<='f')
            n=16*n+(s[i]-'a'+10);
        else
            n=16*n+(s[i]-'A'+10);
    }

    return n;
}

