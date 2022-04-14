
#include <bits/stdc++.h>

#define I_O ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//~~~~~~~~~~~~ Sort Form Of Long~~~~~~~~~~~//
#define ll long long int
#define lls int64_t
#define ld long double
#define db double
#define ull unsigned long long int

//~~~~~~~~~~~~~~Pair~~~~~~~~~~~~~~~~~~//
#define pii pair<int, int>
#define pll pair<lls, lls>
#define pdd pair<db,db>
#define psi pair<string,int>
#define vi vector<int>
#define vl vector<lls>
#define vd vector<db>
#define vs vector<string>
#define vb vector<bool>
#define vpi vector<pii>
#define vpl vector<pll>
#define vpd vector<pdd>
#define vpsi vector<psi>
#define vvi vector<vector<int>>

//~~~~~~~~~~~~~~Vector~~~~~~~~~~~~~~~~~//
#define pb push_back
#define pf push_front
#define MP make_pair
#define in insert
#define ff first
#define ss second
#define al(v) v.begin(),v.end()
#define alr(v) v.rbegin(), v.rend()
#define srt(v) sort(al(v))
#define srtr(v) sort(al(v), greater<int>());
#define len(x) ((int)(x).length())
#define sz(x) ((int)(x).size())
#define rev(v) reverse(al(v))
#define btcnt(n) __builtin_popcount(n)
#define acl(v, n) accumulate(al(v), n)
#define eb emplace_back
#define Lrt(s, c) rotate(s.begin(), s.begin() + c, s.end())
#define Rrt(s, c) rotate(s.begin(), s.begin() + s.size() - c, s.end())
#define lb(v, kk) lower_bound(al(v), kk) - v.begin()
#define ub(v, kk) upper_bound(al(v), kk) - v.begin()
#define tpu(str) transform(al(str), str.begin(), ::toupper)
#define tpl(str) transform(al(str), str.begin(), ::tolower)
#define cignr cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define mxv(v) *max_element(al(v))
#define mnv(v) *min_element(al(v))

const int MOD = 1e9 + 7;
const ll INF = 2e18;
const int mxn = 2e9 + 9;
const int mxd = 2e5 + 5;
const int mxa = 2e6 + 5;

//~~~~~~~~~~~~~~~~~~Function~~~~~~~~~~~~~~~~~~~~//
lls gcd(lls a, lls b){ if(b == 0LL) return a; return gcd(b, a % b); }
lls lcm(lls a, lls b){ return (a / gcd(a, b) * b); }
lls maxll(lls x, lls y){ return x > y ? x : y; }
lls minll(lls x, lls y){ return x < y ? x : y; }

//~~~~~~~~~~~~~~~Loops and Short~~~~~~~~~~~~~~~~//

#define PI acos(-1)
#define Cn continue
#define Br break
#define off return 0
#define N '\n'
#define fopen freopen("input.txt", "r", stdin);
#define rep(i, n) for(lls i = 0; (lls)i < n; i++)
#define repn(i, a, b) for(lls i = (lls)(a); i < (lls)(b); i++)
#define repr(i, a, b) for(lls i = (lls)(a) - 1; i >= (lls)(b); i--)
#define test_case() int T; cin >> T; while(T--)

using namespace std;

// Stores the accessible directions
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

// ===================================~~~~~~ SOLUTION STARTS HERE ~~~~~~=================================== //

//int a, b, c, d, e, res = 0, ans = 0, prod = 1, n, m, cnt = 0, k, l, r, s, t, x, y, f, i, j, p;

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (!i or !j) dp[i][j] = 0;
            else if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } 
            else dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}

void Run_Case()
{
    int n;
    cin >> n;
    int price[n], weight[n];

    rep (i, n) cin >> price[i] >> weight[i];

    int g, mx_weight;
    cin >> g;

    lls res = 0;
    for (int i = 0; i < g; i++) {
        cin >> mx_weight;
        res += knapSack(mx_weight, weight, price, n);
    }

    cout << res << N;
}

int main()
{
    I_O
    test_case()
    {
        Run_Case();
    }

    off;
}
