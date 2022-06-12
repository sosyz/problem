#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll box[1000005];
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    ll n, k, t;
    cin >> n >> k;
    if (k >= n - 1) {
        cout << 0;
        return 0;
    }
    box[0] = 0;
    for (ll i = 1; i < n; i++) {
        cin >> t;
        box[i] = box[i - 1] + t;
    }

    register ll maxn = 0;
    for (register ll i = 1; i <= n - k; i++) {
        maxn = max(maxn,  box[i + k - 1] - box[i - 1]);
    }
    cout << box[n - 1] - maxn;
    return 0;
}