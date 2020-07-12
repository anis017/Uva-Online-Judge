#include<bits/stdc++.h>
using namespace std;
int palin(long long n)
{
    long long m,rev;
    m=n;
    rev=0;
    while(n>0)
    {
        int dig=n%10;
        rev=rev*10+dig;
        n/=10;
    }
    if(rev==m)
        return true;
    return false;
}
int prime(long long n)
{
    int i,flag=0;

    if(n<2)
        return false;
    else
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            flag=1;
    }
    if(flag)
        return true;
    return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n,i,j,d,t;
    while(cin >>n)
    {
        t=n*2;
        cout <<t<<endl;
       if(!prime(n)&&palin(n))
        break;
    }
    return 0;
}

