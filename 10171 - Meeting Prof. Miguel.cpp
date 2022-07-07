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
#define test_case() int T; T = 1; while(T--)

using namespace std;

vi adjM[50], adjY[50], parM[50], parY[50];

void BFS(vi gr[50], vi pr[50], vi &dist, int so) {
   dist[so] = 0;
   priority_queue<pii, vpi, greater<pii>> pq;
   pq.push({0, so});

   while (!pq.empty()) {
      int u = pq.top().ss, d = pq.top().ff;
      pq.pop();

      for (int i = 0; i < gr[u].size(); i++) {
         int v = gr[u][i], nd = pr[u][i] + d;
         if (nd < dist[v]) {
            dist[v] = nd;
            pq.push({nd, v});
         }
      }
   }
}

void Run_Case() 
{
   int m;
   while (cin >> m and m) {
      for (int i = 0; i < 30; i++) {
         adjM[i].clear();
         adjY[i].clear();
         parM[i].clear();
         parY[i].clear();
      }

      while (m--) {
         char t, d, xx, yy;
         int cost;
         cin >> t >> d >> xx >> yy >> cost;

         int x = xx - 'A', y = yy - 'A';
         if (t == 'Y') {
            adjY[x].push_back(y);
            parY[x].push_back(cost);

            if (d == 'B') {
               adjY[y].push_back(x);
               parY[y].push_back(cost);
            }
         } else {
            adjM[x].push_back(y);
            parM[x].push_back(cost);

            if (d == 'B') {
               adjM[y].push_back(x);
               parM[y].push_back(cost);
            }
         }
      }

      char xx, yy;
      cin >> xx >> yy;

      int x = xx - 'A', y = yy - 'A';

      vi distY(30, INT_MAX), distM(30, INT_MAX);

      BFS(adjY, parY, distY, x);
      BFS(adjM, parM, distM, y);

      vpi v;
      int res = INT_MAX, id = -1;
      for (int i = 0; i < 30; i++) {
         res = min(res, distY[i] + distM[i]);
         v.push_back({distY[i] + distM[i], i});
      }

      if (res == INT_MAX) cout << "You will never meet." << N;
      else {
         srt(v);
         cout << res;
         for (int i = 0; i < 30; i++) {
            if (v[i].ff != res) break;
            cout << " " << (char) (v[i].ss + 'A');
         }
         cout << N;
      }
   }
}

signed main()
{
   I_O
   test_case()
   {
      Run_Case();
   }

   return 0;
}
