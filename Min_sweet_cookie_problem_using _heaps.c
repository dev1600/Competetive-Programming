#include <stdio.h>

void swap(int *a,int *b)
 {
     int t=*a;
     *a=*b;
     *b=t;
 }
 void heapify(long long int a[],int n,int i)
 {
    // printf("n value %d\n",n);
     int smallest=i;
     int left=2*i+1;
     int right=2*i+2;
     if(left<n&&a[left]<a[smallest])
        smallest=left;
    if(right<n&&a[right]<a[smallest])
        smallest=right;
    if(smallest!=i)
    {
        swap(&a[i],&a[smallest]);
        heapify(a,n,smallest);
    }
 }
 long long int Peek(long long int a[],int n)
 {
    
     int t=a[0];
   
    swap(&a[0],&a[n-1]);
    
    heapify(a,n-1,0);
    return t;
 }
 void Push(long long int a[],int n)
 {
     if(n>0)
     {
         if(a[n/2]>a[n])
         {
             swap(&a[n/2],&a[n]);
             Push(a,n/2);
         }
     }
 }
 int cookies(long long int k,long long int a[],int *n)
 { int count=0;

     for(int i=*n/2-1;i>=0;i--)
     {
         heapify(a,*n,i);
     }
     while(a[0]<k && *n>-1)
     {
         int p1,p2;
         p1=Peek(a,*n);
  
         p2=Peek(a,*n-1);
         *n-=1;
        
         int temp=p1+2*p2;
       
         a[*n-1]=temp;
       
         Push(a,*n-1);
    
         count++;
     }
      if(*n<=0)
      return -1;
      return count;
 }
 int main()
 {
     long long int a[1000000];
     long long int k;
     int n;
     scanf("%d",&n);
     scanf("%lld",&k);
     int temp=n;
     for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
     int count=cookies(k,a,&n);
    printf("%d",count);
 }
