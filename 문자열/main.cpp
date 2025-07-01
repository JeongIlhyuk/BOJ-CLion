// Problem: 문자열
// URL: https://www.acmicpc.net/problem/1120
// Time Limit: 2000 ms
// Memory Limit: 128 MB

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string x, y;
    cin >> x >> y;

    int min_diff = y.length();

    for (int i = 0; i <= y.length() - x.length(); ++i)
    {
        int cnt = 0;
        for (int j = 0; j < x.length(); ++j)
        {
            if (y[i + j] != x[j])cnt++;
        }
        min_diff = min(min_diff, cnt);
    }

    cout << min_diff;

    return 0;
}
