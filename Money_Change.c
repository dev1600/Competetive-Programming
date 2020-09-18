#include <stdio.h>

void main()
{
    int m;
    scanf("%d",&m);
    int i=0;
    int coin=0;
    while(m/10!=0)
    {
        coin++;
        m=m-10;
    }
    while(m/5!=0)
    {
        coin++;
        m=m-5;
    }
    coin+=m;
    printf("%d",coin);
}
