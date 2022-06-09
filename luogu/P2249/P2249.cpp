#include <bits/stdc++.h>

int n, m;
using namespace std;
int box[1000005] = {};
int findNum(int x)
{ // value start end
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (box[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    if (box[l] == x)
        return l + 1; //找到了就输出他的位置
    else
        return -1; // 没找到输出-1
}

int main()
{

    cin >> n >> m;
    // box.resize(n + 5);
    for (register int i = 0; i < n; i++)
        cin >> box[i];

    register int aq;
    for (register int i = 0; i < m; i++)
    {
        cin >> aq;
        cout << findNum(aq) << " ";
    }
    return 0;
}