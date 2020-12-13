#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void Enqueue(long long int s1[],long long int s2[],int *top)
{
    long long int e;
    scanf("%lld",&e);
    s1[++(*top)]=e;

}
void Dequeue(long long int s1[],long long int s2[],int *top)
{
    for(int i=0;i<=*top;i++)
    {
        s2[i]=s1[*top-i];
    }
    
    *top-=1;
    for(int i=0;i<=*top;i++)
    {
        s1[i]=s2[*top-i];
        
    }

}
void Display(long long int s1[],long long int s2[],long long int res[],int *top,int *f)
{
    for(int i=0;i<=*top;i++)
    {
        s2[i]=s1[*top-i];
      
    }
    printf("%lld \n",s2[*top]);
   
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int s1[100000];
    long long int s2[100000];
    long long int res[10000];
    int top=-1;
    int f=-1;
    for(int i=0;i<n;i++)
    {
        int q;
        scanf("%d",&q);
        if(q==1)
        {
            Enqueue(s1,s2,&top);
        }
        else if(q==2)
        {
            Dequeue(s1,s2,&top);
        }
        else if(q==3)
        {
            Display(s1,s2,res,&top,&f);
        }
    }
   
    return 0;
}
