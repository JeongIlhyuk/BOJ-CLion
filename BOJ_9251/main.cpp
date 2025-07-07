// Problem: LCS
// URL: https://www.acmicpc.net/problem/9251
// Time Limit: 100 ms
// Memory Limit: 256 MB

/*
문제:
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력:
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력:
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

알고리즘 분류:
다이나믹 프로그래밍, 문자열, 최장 공통 부분 수열 문제
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

    string s1, s2;
    cin >> s1 >> s2;


    int lcs = 0;
    vector<int> dp(s1.length());
    vector<int> arr(s1.length());
    for (int i = 1; static_cast<size_t>(i) < s1.length(); ++i)
    {
        for (int j = 0; static_cast<size_t>(j) < i; ++j)
        {
            if (s2[j]<s2[i]&&dp[j]<dp[i])
            {

            }
        }
    }
    cout << lcs;
}
