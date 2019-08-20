#include <stdio.h>

int binsearch(int x,int v[],int n);


int main(int argc, char const *argv[])
{
    int arr[7]={1,3,5,7,9,12,14};
    int idx=binsearch(7,arr,7);
    printf("%d\n",idx);
    
    return 0;
}


int binsearch(int x,int v[],int n){
    int low,high,mid;

    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(x<v[mid])
            high=mid+1;
        else if(x>v[mid])
            low=mid+1;
        else 
            return mid;
    }
    return -1;//no match
}
//use only one test in while loop
int binsearch2(int x,int v[],int n){
    int low,high,mid;
    low=0;
    high=n-1;

    while(low<high){
        mid=(low+high)/2;
        if(x<=v[mid])
            high=mid;
        else   
            low=mid+1;
    }
    return (x==v[low])?low:-1;
}