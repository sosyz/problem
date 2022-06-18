#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	string n;
	cin >> n >> a >> b;
	for (int i = 0; i < n.size(); i++){
		n[i] -= '0';
	}
	
	for (int i = 0; i < n.size(); i++){
		if (n[i] < 4){
			// 减操作
			if (n[i] + 1 > b){
				// 满足不了，往大变
				if (9 - n[i] > a){
					n[i] += a;
					a = 0;
				}else{
					a -= 9 - n[i];
					n[i] = 9;
				}
			}else{
				// 往小变
				b -= n[i] + 1;
				n[i] = 9;
			}
		}else{
			if (9 - n[i] > a){
				n[i] += a;
				a = 0;
			}else{
				a -= 9 - n[i];
				n[i] = 9;
			}
		}
	}
	for (int i = 0; i < n.size(); i++){
		cout << (int)n[i];
	}
	return 0;
}

