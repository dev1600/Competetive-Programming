#include <stdio.h>

long long int stack[100000];
int top=-1;
int max_index=0;
void Push(int a)
{
    stack[++top]=a;
    if(stack[max_index]<=a)
    {
        max_index=top;
    }
}
void Pop()
{
    if(top==max_index)
    {
        --top;
        max_index=0;
        Find_Maximum();
    }
    else{
        --top;
    }


}
void Find_Maximum()
{
   // long long int max=0;
    for(int i=0;i<=top;i++)
    {
        if(stack[max_index]<stack[i])
            max_index=i;
    }
   // return max;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int q;
        scanf("%d",&q);
        if(q==1)
        {
            long long int a;
            scanf("%lld",&a);
            Push(a);
        }
        else if(q==2)
        {
            Pop();
        }
        else if(q==3)
        {
           // long long int max=Maximum();
            printf("%lld\n",stack[max_index]);
        }

    }
return 0;
}
