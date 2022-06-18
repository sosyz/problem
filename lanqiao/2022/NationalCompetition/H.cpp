// 未完成
#include <bits/stdc++.h>

using namespace std;

struct node {
	int u, v;
	int minuse = 1e17;
	bool view = false;
	node(int u, int v):u(u), v(v){};
};

int use[100005] = {};//连接的电脑数量 
int n, m;
vector<node*> lu;
int dfs(int in, int end){
	//cout << "find:" << in << endl;
	if (in == end) return use[in];//到达
	int minuse = 1e17, now = -1, hava;
	for (int i = 0; i < n - 1; i++){//循环所有边 
 		if (lu[i]->u == in || lu[i]->v == in){// 有一端是 
 		   
 			now = i;
 			
 			cout << in << endl;
 				 // 未计算过
		 		 if (!lu[i]->view){
	 				hava = dfs(lu[i]->u == in ? lu[i]->v : lu[i]->u, end);
	 	            minuse = min(minuse, hava);
			        cout << i << " " << lu[i]->v << " " << hava << " " << minuse << endl;

 				 }
			        lu[i]->view = true;
 		}
 	}
 	if (now == -1){
 		return -1;
 	}
 	cout << "return:" << in << endl;
 	lu[now]->minuse = minuse + use[in];
 	return lu[now]->minuse;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n - 1; i++){
 		cin >> x >> y;
 		lu.push_back(new node(x, y));
 		++use[x];
 		++use[y];
 	}

 	int s, e;
 	for (int i = 0; i < m; i++){
 		cin >> s >> e;
 		if (s == e){
 			cout << 0 <<endl;
 		}else{
 			cout << dfs(s, e) * 2 - use[e] << endl;	
 		}
 	}
	return 0;
}
/*
4 3
1 2
1 3
2 4
2 3
3 4
3 3
*/
