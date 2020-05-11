#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int t,a,c,b,tmp,m,ans,smax,smin;
    vector<int> v;
        while(cin >> a >> b){
        smin=min(a,b);
        smax=max(a,b);
        for(long int i=smin; i<=smax; i++)
        {
            tmp=i;
            c=1;
            while(tmp!=1)
            {
                if(tmp%2==0)
                {
                    tmp=tmp/2;
                }
                else
                {
                    tmp=(3*tmp)+1;
                }
                c++;
            }
             v.push_back(c);
        }
        ans=*max_element(v.begin(),v.end());
            cout << a << " " << b << " " << ans << endl;
            v.clear();
        }
    return 0;
}
