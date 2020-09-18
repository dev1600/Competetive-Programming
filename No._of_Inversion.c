#include <stdio.h>

int temp[100000];int arr[100000];
int Merge(int arr[],int temp[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int count=0;
    while(i<=mid&&j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            count=count+mid-i+1;
        }
    }
    if(i>mid)
    {
         while(j<=ub)
        {
            temp[k]=arr[j];
            j++;k++;
        }
    }else
    {
        while(i<=mid)
        {
            temp[k]=arr[i];
                i++;k++;
        }
    }
        for(k=lb;k<=ub;k++)
            arr[k]=temp[k];
        return count;
}
int MergeSort(int arr[],int temp[],int lb,int ub)
{
    int count=0;
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        count+=MergeSort(arr,temp,lb,mid);
        count+=MergeSort(arr,temp,mid+1,ub);
        count+=Merge(arr,temp,lb,mid,ub);
    }
    return count;
}
void main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",MergeSort(arr,temp,0,n-1));
    /*for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }*/
}
