// https://codeforces.com/problemset/problem/15/A


#include <bits/stdc++.h>

using namespace std;

struct house {
	double l;
	double r;
	int x;
};

inline bool cmp(struct house h1,struct house h2){
	return h1.x < h2.x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	cin >> n >> t;

	house add[1010];
	double x, a;
	for (int i = 0; i < n; i++){
		cin >> x >> a;
		add[i].l = x - (a / 2);
		add[i].r = x + (a / 2);
		add[i].x = x;
	}
 	sort(add, add + n, cmp);  //排序

	int ans = 2;
	double c;
	for (int i = 1; i < n ; i++){
		c = add[i].l  - add[i - 1].r;

		if (c >= t){
			ans += (c > t ? 2 : 1);
			//cout << i << " " << add[i].l << " " << add[i - 1].r << " " << c << endl;
		}

	}

	cout << ans;
	return 0;
}

