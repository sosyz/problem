#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    // 统计正方形
    long long ans[2] = {}, x, y, sum;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x = n - i;
            y = m - j;
            sum = x * y;
            if (j == i)// 正方形
                ans[0] += sum;
            else
                ans[1] += sum;
        }
    }
    cout << ans[0] << " " << ans[1];
    return 0;
}
