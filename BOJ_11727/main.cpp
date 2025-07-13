// Problem: 2×n 타일링 2
// URL: https://www.acmicpc.net/problem/11727
// Time Limit: 1000
// Memory Limit: 256

/*
문제:
N/A

입력:
N/A

출력:
N/A

알고리즘 분류:
N/A
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>
#define MOD 10007

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % MOD;
    }

    cout << dp[n];
}