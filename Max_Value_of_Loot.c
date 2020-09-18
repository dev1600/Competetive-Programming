#include <stdio.h>
#include <math.h>

void main()
{
    int n;
    int w[1000];
    int v[1000];
    float val_unit[1000];
    float max_cost;
    int W;
    scanf("%d",&n);
    scanf("%d",&W);
    int i=0;
    for(i=0;i<n;i++)
     {
         scanf("%d",&v[i]);
         scanf("%d",&w[i]);
     }


    for(i=0;i<n;i++)
     {
         val_unit[i]=(float)v[i]/w[i];
        // val_unit[i]=floor(val_unit[i]*100000)/100000;
     }

    do
    {
        int large=-1;
        for(i=0;i<n;i++)
        {
            if(val_unit[i]>val_unit[large])
            {
                large=i;
            }
        }
        if(w[large]<=W)
        {
            max_cost+=v[large];
            W-=w[large];
        }
        else if(w[large]>W)
        {
            max_cost+=val_unit[large]*W;
            break;
        }
        val_unit[large]=-1;

    }
    while(1);
    int j=(int)max_cost;
    printf("%0.4f",max_cost);
}
