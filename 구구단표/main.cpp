// Problem: 구구단표
// URL: https://www.acmicpc.net/problem/32710
// Time Limit: 500 ms
// Memory Limit: 1024 MB

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> n;

    for (int i = 2; i <= 9; i++)
        if (n%i==0 && n/i <= 9)
        {
            cout << 1;
            return 0;
        }

    cout << 0;

    return 0;
}
