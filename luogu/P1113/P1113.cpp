#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int task[N] = {}, taskTime[N] = {}, maxTime[N] = {};
vector<int> edge[N];


int dfs(int i){
    if (maxTime[i] != 0) return maxTime[i];
    for (auto it = edge[i].begin(); it != edge[i].end(); it++){
        maxTime[i] = max(maxTime[i], dfs(*it - 1));
    }
    maxTime[i] += taskTime[i];
    return maxTime[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int needId;
    for(int i = 0; i < n; i++){
        cin >> task[i] >> taskTime[i];
        while(cin >> needId && needId != 0){
            edge[i].push_back(needId);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, dfs(i));
    }
    cout << ans;
    return 0;
}