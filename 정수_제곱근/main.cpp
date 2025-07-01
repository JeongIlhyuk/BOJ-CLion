// Problem: 정수 제곱근
// URL: https://www.acmicpc.net/problem/2417
// Time Limit: 400 ms
// Memory Limit: 128 MB

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n, result = (1ULL << 63) - 1;
    cin >> n;

    long long left = 0, right = (1LL << 32) - 1;
    while (left <= right)
    {
        const unsigned long long mid = (left + right) / 2;
        if (mid * mid == n)
        {
            cout << mid;
            return 0;
        }

        if (mid * mid > n)
        {
            result = mid;
            right = mid - 1;
            continue;
        }

        left = mid + 1;
    }

    cout << result;

    return 0;
}
