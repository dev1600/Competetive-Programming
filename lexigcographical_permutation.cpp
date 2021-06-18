#include <vector>
#include <string>
#include <iostream>
using namespace std;

void swap(char*,char*);
void Reverse(string &s,int j,int l)
{
    int i=0;
    // int l=s.length();
    int n=l-j;
    while(i<n/2)
    {
        swap(&s[j+i], &s[l-i-1]);
        i++;
    }
}
void swap(char* a,char *b)
{
    char t=*a;
    *a=*b;
    *b=t;
}
void permutation(string &s,int l)
{
    int i;
    int index1=-1;
    for(i=1;i<l;i++)
    {
        if(s[i-1]<s[i])
        {
            index1=i;
        }

    }
    if(index1==-1)
        {
            cout<<"no answer";
            return ;
        }
    int index2=index1;
    for(i=index1;i<l;i++)
    {
        if(s[index1-1]<s[i])
        {
            index2=i;
        }
    }
    swap(&s[index1-1],&s[index2]);
    // cout<<s<<endl;
    Reverse(s,index1,l);
    // char t=s[index1-1];
    // s[index1-1]=s[index2];
    // s[index2]=t;
    // cout<<"String "<<s<<index1<<" "<<index2<<endl;
   // reverse(s,)
    cout<<s;
}
int main(){

    int n;
    string s[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        
        cin>>s[i];
        int l=s[i].length();
        permutation(s[i],l);
        // cout<<s;
    }
}