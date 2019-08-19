#include <stdio.h>

int main(int argc, char const *argv[])
{
    float fahr,celsius;
    float lower,upper,step;
    lower=0;
    upper=300;
    step=20;
    fahr=lower;
    while(fahr<=upper){
        celsius=(5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n",fahr,celsius);
        fahr=fahr+step;
    }
    printf("\n");

    for(fahr=300.0;fahr>=0;fahr=fahr-20.0){
        printf("%3.0f %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
    }
    return 0;
}
