// Problem: IOIOI
// URL: https://www.acmicpc.net/problem/5525
// Time Limit: 1000 ms
// Memory Limit: 256 MB

/*
문제:
N+1개의I와 N개의O로 이루어져 있으면,I와O이 교대로 나오는 문자열을 PN이라고 한다.P1IOIP2IOIOIP3IOIOIOIPNIOIOI...OI(O가 N개)I와O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

입력:
첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다.

출력:
S에 PN이 몇 군데 포함되어 있는지 출력한다.

알고리즘 분류:
문자열
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<int> dp(m);
    for (int i = 2; i < m; ++i)
    {
        dp[i] = dp[i - 1];
        if (s[i] == 'I' && s[i - 1] == 'O' && s[i - 2] == 'I')
        {
            dp[i]++;
        }
        // cout << "dp[" << i << "]:" << dp[i] << " ";
    }

    int cnt = 0;
    for (int i = 2 * n; i < m; ++i)
    {
        if (s[i] == 'I' && s[i - (2 * n)] == 'I' && dp[i] - dp[i - (2 * n)] == n)
        {
            cnt++;
        }
    }

    cout << cnt;
}
