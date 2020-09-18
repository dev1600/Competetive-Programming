#include <stdio.h>

int Majority_Element(int arr[],int n)
{
    int i=0;int count=1;
    int major=0;
    for(i=1;i<n;i++)
    {
        if(arr[major]==arr[i])
        {
            count++;
        }
        else count--;
        if(count==0)
        {
           major=i;
           count=1;
        }
    }
    return arr[major];

}
int Check_Majority(int arr[],int major,int n)
{
    int i=0;int count=0;
    for(i=0;i<n;i++)
    {
        if(major==arr[i])
            count++;
    }
    if(count>n/2)
        return 1;
    else return 0;
}
void main()
{
    int n;
    int arr[100000];
    scanf("%d",&n);
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int major=Majority_Element(arr,n);
    int flag=Check_Majority(arr,major,n);
    printf("%d",flag);
}
