#include <stdio.h>

int getP(int* arr,int p,int n)
{
    int i=0;
    for(i=p;i<n;i++)
    {
        if(arr[i]==0)
        {
            p=i;
            break;

        }
    }
    return p;
}
void main()
{
    int arr[100000]={0};
    int p=3;
    int i=0;
    int j=0;
    int m,n;
    printf("Enter m and n");
    scanf("%d%d",&m,&n);
    int k=0;
    int flag=1;
    for(p=2;p*p<=n;p++)
    {
        if(arr[p]==0)
        {
           for(k=p*p;k<=n;k=k+p)
          {
            arr[k]=1;
          }
        }
       // p=getP(arr,p+1,n);
        //k=p*p;
    }
    while(k<n);

    printf("\n");
    for(i=m;i<=n;i++)
    {
        if(i==2)
            printf("%d",i);
        else if(i==1)
            continue;
       else  if(arr[i]==0&&i%2!=0)
            printf("%d",i);
            else continue;
        printf("\n");
    }


}
