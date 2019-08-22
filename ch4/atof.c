#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
//double atof2(char s[]);
int main(int argc, char const *argv[])
{
    char s[]="123.45e-6";
    printf("atof(%s)=%.10lf\n",s,atof(s));
    
    return 0;
}

/*atof: convert string s to double*/
double atof(char s[]){
    double val,power;
    int i,j,sign,p;
    int sign_power;
    for(i=0;isspace(s[i]);i++)
        ;
    sign=(s[i]=='-')?-1:1;
    if(s[i]=='+'||s[i]=='-')
        i++;
    for(val=0.0;isdigit(s[i]);i++)
        val=10.0*val + (s[i]-'0');
    if(s[i]=='.')
        i++;
    for(power=1.0;isdigit(s[i]);i++){
        val=10.0*val+(s[i]-'0');
        power*=10;
    }
    if(s[i]=='e' || s[i]=='E'){
        ++i;
        sign_power=(s[i]=='-')?-1:1;
        if(s[i]=='+' || s[i]=='-')
            ++i;
        p=0;
        for(;isdigit(s[i]);i++){
            p=p*10+(s[i]-'0');
        }
        for(j=0;j<p;j++){
            power=(sign_power>0)? (power/10.0):(power*10.0);
        }
        
    }
    return sign*val/power;
}


/*atoi*/
int atoi(char s[]){
    double atof(char s[]);
    return (int) atof(s);
}