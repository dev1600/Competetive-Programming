#include <stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
void main()
{
    int W;
    int n;int w[300];
    int i=0;
    int c[301][1000]={0};
    scanf("%d",&W);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    int items=0;
    int weight=0;
    /*for(items=0;items<=n;items++)
    {
        c[items][0]=0;
    }
    for(weight=0;weight<=W;weight++)
    {
        c[0][weight]=0;
    }*/
    for(items=1;items<=n;items++)
    {

        for(weight=1;weight<=W;weight++)
        {
            if(items==0||weight==0)
                c[items][weight]=0;

         else   if(w[items-1]<=weight)
            {
                c[items][weight]=max(c[items-1][weight],c[items-1][weight-w[items-1]]+w[items-1]);

            }
            else
            {

                 c[items][weight]=c[items-1][weight];

            }
        }
    }
    printf("%d",c[n][W]);

}
