// Problem: RGB거리 2
// URL: https://www.acmicpc.net/problem/17404
// Time Limit: 500
// Memory Limit: 128

/*
문제:
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.

입력:
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력:
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

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
    vector cost(n + 1, vector<int>(3));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> cost[i][j];
        }
    }

    int min_cost = 1e9;
    for (int i = 0; i < 3; ++i)
    {
        vector dp(n + 1, vector<int>(3));
        dp[1][i] = cost[1][i];
        dp[1][(i + 1) % 3] = 1e9;
        dp[1][(i + 2) % 3] = 1e9;
        for (int j = 2; j <= n; ++j)
        {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
        }
        min_cost = min(min_cost, min(dp[n][(i + 1) % 3], dp[n][(i + 2) % 3]));
    }

    cout << min_cost;
}
