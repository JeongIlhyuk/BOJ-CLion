// Problem: 스위치
// URL: https://www.acmicpc.net/problem/30460
// Time Limit: 1000
// Memory Limit: 1024

/*
문제:
$i$초에 $A_i$의 점수를 얻는 게임이 있다. $N$초 동안 진행하는 이 게임에서는 점수를 추가로 얻기 위해 $T$초에 스위치를 눌러 $T,T+1,T+2$초에 얻는 점수를 $2$배로 만들 수 있다. $T$초에 스위치를 누르면 $T+3$초부터 다시 스위치를 누를 수 있다.게임이 진행되는 동안 스위치를 적절하게 눌렀을 때 얻을 수 있는 점수의 최댓값을 구해보자.

입력:
첫째 줄에 점수를 얻는 횟수 $N$이 주어진다. $\left( 3\leq N\leq 200\, 000 \right)$둘째 줄에 $i$초에 얻는 점수를 나타내는 정수 $A_i$가 공백으로 구분되어 주어진다. $\left( 1\leq i\leq N;\ |A_i|\leq 1\, 000 \right)$

출력:
얻을 수 있는 점수의 최댓값을 출력한다.

알고리즘 분류:
N/A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    // dp[i][j] = i번째까지 고려했을 때, 마지막 스위치를 j번째에 눌렀을 때 최대 점수
    // j = 0이면 스위치를 아직 안 눌렀거나, 효과가 끝난 상태
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, LLONG_MIN));

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        // 스위치를 안 누르는 경우
        for (int j = 0; j <= i - 1; ++j)
        {
            if (dp[i-1][j] != LLONG_MIN)
            {
                // 이전 스위치 효과가 끝났으면 평범하게 더하기
                if (j == 0 || i > j + 2)
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i]);
                }
                // 이전 스위치 효과가 아직 있으면 2배로 더하기
                else
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + 2 * arr[i]);
                }
            }
        }

        // i번째에 스위치를 누르는 경우
        for (int j = 0; j <= i - 1; ++j)
        {
            if (dp[i-1][j] != LLONG_MIN)
            {
                // 스위치를 누를 수 있는 조건: 이전 스위치가 없거나 쿨다운이 끝났음
                if (j == 0 || i >= j + 3)
                {
                    dp[i][i] = max(dp[i][i], dp[i-1][j] + 2 * arr[i]);
                }
            }
        }
    }

    long long result = LLONG_MIN;
    for (int j = 0; j <= n; ++j)
    {
        result = max(result, dp[n][j]);
    }

    cout << result << "\n";

    return 0;
}
