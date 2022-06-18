#include <bits/stdc++.h>

using namespace std;
/**
 * 还是存在问题 例如 5 5 5 5无法支持
 */
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int *an = new int[n + 5];
	int *bn = new int[n + 5];
	memset(an, 0, n + 5);
	memset(bn, 0, n + 5);
	for (int i = 0; i < n; i++){
		cin >> an[i]; 
	}
	for (int i = 0; i < n; i++){
		cin >> bn[i];
	}
	sort(an, an+n);

	
 	int next = 1, cha, ic, maxadd;
 	bool ccxz = false; 
	while(m > 0){
		cha = 0;
		for (int i = 0; i < next; i++){
			if (ccxz){
				cha += maxadd;
				bn[i] -= maxadd;
			}else{
	            ic = an[next] - an[i];
				// 超出限制 
				if (ic > bn[i]){
					ccxz = true;
					ic = bn[i];
					maxadd = ic;
				}else{
					bn[i] -= ic;
				}
				cha += ic;
			}
			//cout << next << " " << i << endl;
		}
		if (ccxz) cha = next * maxadd;
		//cout << "cha:" << cha << endl;
		
		if (cha > m){
			// 无法普惠 不加了直接出结果 
			m = 0;
		}else{
			m -= cha;
			if (ccxz){
				m = 0;
				//每个加maxadd
				for (int i = 0; i < next; i++){
					an[i] += maxadd;
				}
			}else{
				for (int i = 0; i < next; i++){
					an[i] += an[next] - an[i];
				}
			}
		}
		next++;
	}
	cout << an[0];
	/*
	for (int i = 0; i < n; i++){
		cout << an[i] << " ";
	}
	*/
	return 0;
}


/*
4 5
1 2 3 4
5 5 5 5

4 5
2 7 8 9
3 2 2 2
*/
