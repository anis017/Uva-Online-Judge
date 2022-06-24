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

int l, r, c;
string arr[35][35];
int dist[35][35][35], vis[35][35][35];
int lala[] = {-1, 0, 1};

int dx[] = {0, 0, 0, 0, -1, 1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

struct point {
   int x, y, z;
};

void bfs(point a) {
   point p, b;
   int i, j, k;

   memset(vis, 0, sizeof(vis));
   memset(dist, 0, sizeof(dist));

   queue<point> q;

   q.push(a);

   vis[a.x][a.y][a.z] = 1;
   dist[a.x][a.y][a.z] = 0;

   while (!q.empty()) {
      p = q.front();
      q.pop();

      for (int i = 0; i < 6; i++)  {
         b.x = p.x + dx[i];
         b.y = p.y + dy[i];
         b.z = p.z + dz[i];

         if (b.x < l and b.x >= 0 and b.y < r and b.y >= 0 and b.z < c and b.z >= 0) {

            if (arr[b.x][b.y][b.z] != '#' and !vis[b.x][b.y][b.z]) {
               vis[b.x][b.y][b.z] = 1;
               dist[b.x][b.y][b.z] = dist[p.x][p.y][p.z] + 1;
               q.push(b);
            }
         }
      }
   }
}

void Run_Case() 
{
   int i, j, k, sx, sy, sz, ex, ey, ez;
   while (cin >> l >> r >> c and !(!l and !r and !c)) {
      for (int i = 0; i < l; i++) {
         for (int j = 0; j < r; j++) {
            cin >> arr[i][j];
         }
      }

      for (int i = 0; i < l; i++) {
         for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
               if (arr[i][j][k] == 'S') {
                  sx = i, sy = j, sz = k;
               }

               if (arr[i][j][k] == 'E') {
                  ex = i, ey = j, ez = k;
               }
            }
         }
      }

      point a;
      a.x = sx, a.y = sy, a.z = sz;

      bfs(a);
      if (!vis[ex][ey][ez]) cout << "Trapped!" << N;
      else cout << "Escaped in " << dist[ex][ey][ez] << " minute(s)." << N;
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
