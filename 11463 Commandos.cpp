#include <bits/stdc++.h>

#define I_O ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//~~~~~~~~~~~~ Sort Form Of Long~~~~~~~~~~~//
#define ll long long int
#define int int64_t
#define ld long double
#define db double
#define ull unsigned long long int

//~~~~~~~~~~~~~~Pair~~~~~~~~~~~~~~~~~~//
#define pii pair<int, int>
#define pll pair<int, int>
#define pdd pair<db,db>
#define psi pair<string,int>
#define vi vector<int>
#define vl vector<int>
#define vd vector<db>
#define vs vector<string>
#define vb vector<bool>
#define vpi vector<pii>
#define vpl vector<pll>
#define vpd vector<pdd>
#define vpsi vector<psi>
#define vvi vector<vector<int>>

//~~~~~~~~~~~~~~Shorts~~~~~~~~~~~~~~~~~//
#define ff first
#define ss second
#define al(v) v.begin(),v.end()
#define alr(v) v.rbegin(), v.rend()
#define srt(v) sort(al(v))
#define srtr(v) sort(al(v), greater<int>());
#define len(x) ((int)(x).size())
#define rev(v) reverse(al(v))
#define btcnt(n) __builtin_popcountll(n)
#define acl(v, n) accumulate(al(v), n)
#define Lrt(s, c) rotate(s.begin(), s.begin() + c, s.end())
#define Rrt(s, c) rotate(s.begin(), s.begin() + s.size() - c, s.end())
#define lb(v, kk) lower_bound(al(v), kk) - v.begin()
#define ub(v, kk) upper_bound(al(v), kk) - v.begin()
#define tpu(str) transform(al(str), str.begin(), ::toupper)
#define tpl(str) transform(al(str), str.begin(), ::tolower)
#define cignr cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define mxv(v) *max_element(al(v))
#define mnv(v) *min_element(al(v))

const int mod = 1e9 + 7;
const int INF = 2e18;
const int mxn = 2e9 + 9;
const int mxd = 2e5 + 5;
const int mxa = 2e6 + 5;

//~~~~~~~~~~~~~~~~~~Function~~~~~~~~~~~~~~~~~~~~//
int gcd(int a, int b){ if(b == 0LL) return a; return gcd(b, a % b); }
int lcm(int a, int b){ return (a / gcd(a, b) * b); }
int maxll(int x, int y){ return x > y ? x : y; }
int minll(int x, int y){ return x < y ? x : y; }

//~~~~~~~~~~~~~~~Loops and Short~~~~~~~~~~~~~~~~//

#define PI acos(-1)
#define N '\n'
#define Read(x) freopen(x, "r", stdin)
#define Write(x) freopen(x, "w", stdout)
#define rep(i, n) for(int i = 0; (int)i < n; i++)
#define test_case() int T; cin >> T; while(T--)

using namespace std;

vi adj[105];
int n, r;

void bfs(int src, int des) {
   queue<int> q;
   q.push(src);
   vi vis(105, 0), level(105, 0), level2(105, 0), dist(105, 0);
   level[src] = 0;
   vis[src] = 1;
   while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto aa: adj[u]) {
         if (!vis[aa]) {
            q.push(aa);
            level[aa] = level[u] + 1;
            vis[aa] = 1;
         }
      }
   }

   q.push(des);
   level2[des] = 0;
   vis.clear();
   vis.resize(105, 0);
   vis[des] = 1;
   while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto aa: adj[node]) {
         if (!vis[aa]) {
            q.push(aa);
            level2[aa] = level2[node] + 1;
            vis[aa] = 1;
         }
      }
   }

   int ans = 0;
   for (int i = 0; i < 105; i++) {
      ans = max(ans, level[i] + level2[i]);
   }
   cout << ans << N;
}

void Run_Case() 
{
   cin >> n >> r;
   for (int i = 0; i < 105; i++) adj[i].clear();
   while (r--) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   int s, v;
   cin >> s >> v;
   bfs(s, v);
   for (int i = 0; i < 105; i++) adj[i].clear();
}

signed main()
{
   int cnt = 1;
   I_O
   test_case()
   {
      cout << "Case " << cnt++ << ": ";
      Run_Case();
   }

   return 0;
}
