#include <stdio.h>

void main()
{
    int dist;
    int max;
    int n;
    int stops[300];
    scanf("%d%d%d",&dist,&max,&n);
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&stops[i]);
    }
    int current=0;
    int last=0;
     int j=0;
     i=0;
     sort(stops);
     if(dist-stops[n-1]>max)
     {
         printf("-1");
         exit(0);
     }
     for(i=1;i<n;i++)
     {
         if(stops[i]-stops[i-1]>max)
         {
             printf("-1");
             exit(0);
         }
     }
    while(current<n&&dist>max)
    {
        if(dist-current<=max)
            break;

        while(stops[current]-stops[last]<=max&&current<=n)
        {
            current+=1;
        }
        ++j;
        last=current;
    }
    printf("%d",j);
}
