/*

 ALLAH IS ALMIGHTY              ******BISMILLAHIR RAHMANIR RAHIM.******              ALLAH IS ALMIGHTY
                                    ```````````````````````````````
                                        AUTHOR: ANISUR RAHAMAN
                                            BSMRSTU(SHIICT)
                                                ID:017

                                               !!!!!!!!
                                               !!!!!!!!
                                               !!!!!!!!
                                               !!!!!!!!
                                               !!!!!!!!
                                               !!!!!!!!
                                               !!!!!!!!
                                               !!!!!!!!
                                               !!!!!!!!
                                           ****!!!!!!!!****
                                            **************
                                             ************
                                              **********
                                               ********
                                                ******
                                                 ****
                                                  **

 _____________________________________________________________________________________________________
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 `````````````````````````````````````````````````````````````````````````````````````````````````````
 ******                                                                                         ******
 *****                                                                                           *****
 ****                                                                                             ****
 ***                                                                                               ***
 **                                                                                                 **
 *                                                                                                   *
         $$$$$$$$$$$$$$         $$$$$$           $$$$$$$$    $$$$$$$$$$        $$$$$$$$$$$$$$$$
       $$$$$$$$$$$$$$$$$$       $$$$$$$           $$$$$$    $$$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$
      $$$$$$$$$$$$$$$$$$$$      $$$$ $$$           $$$$    $$$$$$$$$$$$$$    $$$$$$$$$$$$$$$$$$$$$
      $$$$$$        $$$$$$      $$$$  $$$          $$$$        $$$$$$        $$$$$$
      $$$$            $$$$      $$$$   $$$         $$$$         $$$$         $$$$$
      $$$$            $$$$      $$$$    $$$        $$$$         $$$$         $$$$$$
      $$$$     $$     $$$$      $$$$     $$$       $$$$         $$$$         $$$$$$$$$$$$$$$$$$
      $$$$$$$$$$$$$$$$$$$$      $$$$      $$$      $$$$         $$$$          $$$$$$$$$$$$$$$$$$
      $$$$$$$$$$$$$$$$$$$$      $$$$       $$$     $$$$         $$$$           $$$$$$$$$$$$$$$$$$
      $$$$            $$$$      $$$$        $$$    $$$$         $$$$                       $$$$$$
      $$$$            $$$$      $$$$         $$$   $$$$         $$$$                        $$$$$
      $$$$            $$$$      $$$$          $$$  $$$$        $$$$$$                      $$$$$$
      $$$$            $$$$      $$$$           $$$ $$$$    $$$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$$$$
     $$$$$$          $$$$$$    $$$$$$           $$$$$$$     $$$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$
    $$$$$$$$        $$$$$$$$  $$$$$$$$           $$$$$$      $$$$$$$$$$        $$$$$$$$$$$$$$$$

                            LETS START OUR JOURNEY...................

*/

#include<bits/stdc++.h>
#define I_O ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pf push_front
#define in insert
#define ff first
#define ss second
#define off return 0
#define MP make_pair
#define MOD 1000000007
#define ll long long int
#define ld long double
#define snll(a) scanf("%lld", &a)
#define snll2(a,b) scanf("%lld %lld", &a,&b)
#define snll3(a,b,c) scanf("%lld %lld %lld", &a,&b,&c)
#define snl(b) scanf("%d", &b)
#define snl2(a,b) scanf("%d %d", &a,&b)
#define snl3(a,b,c) scanf("%d %d %d", &a,&b,&c)
#define sns(str) scanf("%s", &str)
#define ptl(a) printf("%d\n", a)
#define pts(str) printf("%s\n", str)
#define ptll(a) printf("%lld\n", a)
#define ptl2(a,b) printf("%d %d\n", a,b)
#define ptll2(a,b) printf("%lld %lld\n", a,b)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define pi acos(-1)
#define C continue
#define B break
#define N "\n"
#define al(v) v.begin(),v.end()
#define srt(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    //system("COLOR F5");
    I_O
    int n, c = 1;
    while(cin>>n)
    {
        cin.ignore();
        string str;
        set<int> s;
        map<char, int> m;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            cin>>str;
            for(int j=0; j<str.size(); j++)
                m[str[j]]++;
            for(auto x: m)
                s.insert(x.ss);
		  if(s.size() == m.size() && s.size()>1) ans++;
		  s.clear();
		  m.clear();
        }
        cout << "Case " << c << ": " << ans << N;
        c++;
    }
    off;
}
//system("COLOR F5");
/******************************************* THE END *************************************************/

