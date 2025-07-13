// Problem: LCS 2
// URL: https://www.acmicpc.net/problem/9252
// Time Limit: 100
// Memory Limit: 256

/*
문제:
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력:
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력:
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.

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

    string s1, s2;
    cin >> s1 >> s2;
    vector dp(s1.size() + 1, vector<int>(s2.size() + 1));
    vector route(s1.size() + 1, vector<pair<int, int>>(s2.size() + 1));

    int idx1 = 0, idx2 = 0, last_idx1 = 1, last_idx2 = 1;
    int max_length = 0;
    for (int i = 1; i <= s1.size(); ++i)
    {
        for (int j = 1; j <= s2.size(); ++j)
        {
            route[i][j] = {idx1, idx2};
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (s1[i - 1] == s2[j - 1] && dp[i - 1][j - 1] + 1 > dp[i][j])
            {
                idx1 = i;
                idx2 = j;
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_length)
                {
                    max_length = dp[i][j];
                    last_idx1 = i;
                    last_idx2 = j;
                }
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << '\n';
    if (dp[s1.size()][s2.size()] == 0)
    {
        return 0;
    }

    vector<char> stk;
    idx1 = last_idx1;
    idx2 = last_idx2;
    while (idx1 && idx2)
    {
        // cout << "idx:" << idx << '\n';
        stk.push_back(s1[idx1 - 1]);
        idx1 = route[idx1][idx2].first;
        idx2 = route[idx1][idx2].second;
    }

    while (!stk.empty())
    {
        cout << stk.back();
        stk.pop_back();
    }
}
