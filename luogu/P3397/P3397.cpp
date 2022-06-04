#include <iostream>

using namespace std;
int square[1005][1005] = {};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x[2], y[2];
	for (int i = 0; i < m; i++){
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		for (int j = x[0] - 1; j < x[1]; j++){
			for (int k = y[0] - 1; k < y[1]; k++){
				square[j][k]++;
			}
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << square[i][j] << " ";
		cout << endl;
	}
	return 0;
}


