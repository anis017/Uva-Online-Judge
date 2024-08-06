#include <bits/stdc++.h>
using namespace std;

vector<bool> vis, dist;
vector<vector<int>> g;

void asn(int n) {
   vis.assign(n, false);
   g.assign(n, vector<int>());
}

void add_edge(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

// determine shortest path node a to b using BFS
void BFS(int node) {
    queue<int> q;
    q.push(node);

    dist[node] = 0, vis[node] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto aa: g[cur]) {
            if (vis[aa] == 0) {
                dist[aa] = dist[cur] + 1;
                vis[aa] = 1;
                q.push(aa);
            }
        }
    }
}

void bfs(int u)
{
    queue<int> q;
  
    q.push(u);
    vis[u] = true;
  
    while (!q.empty()) {
  
        int node = q.front();
        q.pop();
  
        cout << node << " ";
   
        for (auto aa: g[node]) {
           if (!vis[aa]) {
              q.push(aa);
              vis[aa] = true;
           }
        }
    }
}
 
int main()
{
   int n, e;
   cin >> n >> e;
   asn(n);

   int a, b;
   for (int i = 0; i < e; i++) {
      cin >> a >> b;
      add_edge(a, b);
   }

   for (int i = 0; i < n; i++) {
      if (!vis[i]) {
         bfs(i);
      }
   }

   return 0;
}