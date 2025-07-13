// Problem: 2×n 타일링
// URL: https://www.acmicpc.net/problem/11726
// Time Limit: 1000
// Memory Limit: 256

/*
문제:
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

입력:
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력:
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

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
        dp[i] = (dp[i - 2] % MOD + dp[i - 1] % MOD) % MOD;
    }

    cout << dp[n];
}
