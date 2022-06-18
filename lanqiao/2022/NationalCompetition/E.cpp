#include <bits/stdc++.h>

using namespace std;

struct node {
	int u, v;
	int c;
	int minuse = 1e17;
	node(int u, int v, int c):u(u), v(v), c(c){};
};

int city[1005] = {};
bool viewCity[1005];
vector<node*> lu;
int n, m;

int dfs(int in){
	//cout << "find:" << in << endl;
	if (in == n) return 0;//到达 
	int minuse = 1e17, now = -1, hava;
	for (int i = 0; i < m; i++){
 		if (lu[i]->u == in){
 			now = i;
 			if (viewCity[in]){
 				// 计算过
				 return  lu[i]->minuse;
 			}else{
 				// 未计算过
 				hava = dfs(lu[i]->v);
 	            minuse = min(minuse, city[in] + lu[i]->c + hava);
		        //cout << i << " " << lu[i]->v << " " << hava << " " << minuse << endl;
 			}
 		}
 	}
 	if (now == -1){
 		return -1;
 	}
 	//cout << "return:" << in << endl;
 	lu[now]->minuse = minuse;
 	return lu[now]->minuse;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> city[i];
		viewCity[i] = false;
	}
 	int u, v, c;
 	for (int i = 0; i < m; i++){
 		cin >> u >> v >> c;
 		lu.push_back(new node(u, v, c));
 	}
	
	int ans = 0;
	ans = dfs(1);
 	cout << ans - city[1];
	return 0;
}
/*
4 4
5 7 3 4
1 2 4
1 3 5
2 4 3
3 4 5
*/
