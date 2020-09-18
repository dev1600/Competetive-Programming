#include <stdio.h>
int Binary_Search(int a[],int s,int n)
{
    int high=n-1;
    int low=0;
    int mid=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(s>a[mid])
        {
            low=mid+1;
        }
        else if(s<a[mid])
        {
            high=mid-1;
        }
        else if(s==a[mid])
        {
            return mid;
        }
    }
    return low;
}
void main()
{
    int n;
    int ser;
    int a[100000];
    int s[100000];
    scanf("%d",&n);
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&ser);
    for(i=0;i<ser;i++)
    {
        scanf("%d",&s[i]);
    }
    for(i=0;i<ser;i++)
    {
        int index=Binary_Search(a,s[i],n);
        printf("%d ",index);
    }
}
