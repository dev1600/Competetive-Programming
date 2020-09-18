#include <stdio.h>
#include <string.h>

int Min(int a,int b,int c)
{
    return (a<b)?(a<c?a:c):(b<c?b:c);
}
void main()
{
    char a[100];
    char b[100];
    int c[101][101];
    scanf("%s",&a);
    scanf("%s",&b);
    int i=0,j=0;
    int length_a=strlen(a);
    int length_b=strlen(b);
    //printf("%d",length_a);
    for(i=0;i<=length_a;i++)
      {
          c[i][0]=i;
      }
    for(j=0;j<=length_b;j++)
     {
         c[0][j]=j;
     }
    // printf("%d",c[j-1][0]);
    for(i=1;i<=length_a;i++)
    {
        for(j=1;j<=length_b;j++)
        {
            if(b[j-1]==a[i-1])
            {
               c[i][j]=c[i-1][j-1];
               //printf("%d\t",Min(c[i][j-1],c[i-1][j],c[i-1][j-1]));
            }
            else
            {
              // printf("%d\t",Min(c[i][j-1],c[i-1][j],c[i-1][j-1]));
               c[i][j]=1+Min(c[i][j-1],c[i-1][j],c[i-1][j-1]);
            }
        }
    }
    printf("%d",c[length_a][length_b]);
}
