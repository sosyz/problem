#include <bits/stdc++.h>

using namespace std;
int vum[400] = {};
bool vv[400];
int n, m, k;
int mdts(int m, int d){
	int month[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	int ans = 0;
	for (int i = 0; i < m; i++) ans += month[i];
	return ans += d;
}
int dp(int ans){
	int maxn = 0, use;
	for (int i = 0; i < 365; i++){
		if (!vv[i] && maxn < vum[i]){
		    // 小 采取
			use = i;
			maxn = vum[i];
		}
	}
	if (maxn != 0){
		// 有采用 左右7天设为浏览过
		if (ans + maxn > m){
			// 过大不使用
			vv[use] = true; 
		}else{
			for (int i = use - k + 1; i < use + k - 1; i++){
				vv[i] = true;
			}
		}
	}
	return maxn;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int mt, d, v, dd;
	for (int i = 0; i < n; i++){
		cin >> mt >> d >> v;
		dd = mdts(mt, d);
		vum[dd] = v;
		vv[dd] = false;
	}
	int ans = 0, get;
	while(ans < m){
		get = dp(ans);
		if (get == 0){
			// 没有可用的
			break; 
		}else if (ans + get <= m) {
			ans += get;
		}
	}
	cout << ans;
	return 0;
}

/*
4 16 3
1 1 1
1 3 2 
1 4 4
1 6 8

4 20 7
1 1 5
1 2 10
1 10 15
1 12 8
*/
