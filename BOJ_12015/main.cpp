// Problem: 가장 긴 증가하는 부분 수열 2
// URL: https://www.acmicpc.net/problem/12015
// Time Limit: 1000
// Memory Limit: 512

/*
문제:
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10,20, 10,30, 20,50} 이고, 길이는 4이다.

입력:
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai≤ 1,000,000)

출력:
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

알고리즘 분류:
이분 탐색, 가장 긴 증가하는 부분 수열 문제
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> dp(n + 1);
    for (long long i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }


    for (long long i = 1; i < n + 1; i++)
    {
        dp[i] = 1;
        for (long long j = 1; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
