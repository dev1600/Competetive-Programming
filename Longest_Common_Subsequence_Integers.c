#include <stdio.h>
int Max(int a,int b)
{
    return a>b?a:b;
}
void main()
{
    int m,n;
    int i=0,j=0;
    long long a[100],b[100];
    long long c[101][101];
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%lld",&a[i]);
    }

    scanf("%d",&n);

    for(j=0;j<n;j++)
    {
        scanf("%lld",&b[j]);
    }

    for(i=0;i<=m;i++)
    {
          c[0][i]=0;
    }
    for(j=0;j<=n;j++)
     {
         c[j][0]=0;
     }

     for(i=1;i<=n;i++)
     {
         for(j=1;j<=m;j++)
         {
             if(a[j-1]==b[i-1])
             {
                 c[i][j]=c[i-1][j-1]+1;
             }
             else
             {
                c[i][j]=Max(c[i-1][j],c[i][j-1]);
             }
         }
    }
    printf("%lld",c[n][m]);
}
