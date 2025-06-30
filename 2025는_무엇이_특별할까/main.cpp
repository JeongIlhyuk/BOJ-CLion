// Problem: 2025는 무엇이 특별할까?
// URL: https://www.acmicpc.net/problem/33541
// Time Limit: 1000 ms
// Memory Limit: 1024 MB

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    for (int i = x + 1; i < 10000; ++i)
    {
        const int sum = i / 100 + i % 100;
        if (sum * sum == i)
        {
            cout<<i;
            return 0;
        }
    }

    cout<<-1;
    return 0;
}
