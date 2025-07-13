// Problem: 타일 채우기
// URL: https://www.acmicpc.net/problem/2133
// Time Limit: 2000
// Memory Limit: 128

/*
문제:
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

입력:
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

출력:
첫째 줄에 경우의 수를 출력한다.

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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[n];
}
