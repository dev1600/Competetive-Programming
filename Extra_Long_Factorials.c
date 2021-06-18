#include <stdio.h>
int multiply(int x,int fact[],int size)
{
    int carry=0;
    for(int i=0;i<size;i++)
    {
        int prod=fact[i]*x+carry;
        fact[i]=prod%10;
        carry=prod/10;
        
    }
    while (carry)
    {
        fact[size]=carry%10;
        carry=carry/10;
        size++;
    }
    
    return size;
}
// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
        int arr[1000]={0};
        arr[0]=1;
        int size=1;
        
        for(int i=2;i<=n;i++)
        {
            size=multiply(i,arr,size);
        }
        for(int i=size-1;i>=0;i--)
        {
            printf("%d",arr[i]);
        }
        
    

}
int  main(){
    extraLongFactorials(5);
}