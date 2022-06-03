#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
int f[MAXN];
vector<int> edge[MAXN];

void dfs(int i, int v){
    if(f[i]) return;
    f[i] = v;
    for (auto it = edge[i].begin(); it != edge[i].end(); it++){
        dfs(*it, v);
    }
}

int main(){
    int n, m, u, v;
    cin >> n >> m;
    memset(f, 0, n + 5);
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        edge[v].push_back(u);
    }
    for (int i = n; i; i--){
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++){
        cout << f[i] << " ";
    }
}