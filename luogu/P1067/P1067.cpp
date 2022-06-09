#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    stringstream ss;
    int n, s;
    cin >> n;
    for (int i = n; i >= 0; i--){
        cin >> s;
        if (s != 0){
            // 输出符号位
            ss << (s > 0 ? "+" : "-");
            // 判断s是否为1，否输出s的绝对值，为1不输出
            ss << (abs(s) == 1 ? "" : to_string(abs(s)));
            
            if (i > 1) ss << "x^" << i; // 0次以上输出指数
            else if (i == 1) ss << "x"; // 1次方直接输出x
            else ss << (abs(s) == 1 ? "1" : ""); // 0次根据s是否为1，为1输出1
        }

    }
    string cs = ss.str();
    
    // 去除开头的加号
    if (cs[0] == '+') cs = cs.substr(1);
    cout << (cs == "" ? "0" : cs);
    return 0;
}