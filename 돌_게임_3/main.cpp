// Problem: 돌 게임 3
// URL: https://www.acmicpc.net/problem/9657
// Time Limit: 1000 ms
// Memory Limit: 128 MB

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> win(n + 1, false);

    // 기본 케이스
    if (n >= 1) win[1] = false;
    if (n >= 2) win[2] = true;
    if (n >= 3) win[3] = false;
    if (n >= 4) win[4] = false;

    for (int i = 5; i <= n; i++) {
        if (!win[i-1] || !win[i-3] || !win[i-4]) {
            win[i] = true;
        }
    }

    cout << (win[n] ? "CY" : "SK") << endl;

    return 0;
}
