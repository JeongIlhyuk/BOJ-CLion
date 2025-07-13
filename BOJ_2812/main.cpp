// Problem: 크게 만들기
// URL: https://www.acmicpc.net/problem/2812
// Time Limit: 1000
// Memory Limit: 128

/*
문제:
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

입력:
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

출력:
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다.

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

    int n, k;
    cin >> n >> k;
    string num;
    cin >> num;
    vector<char> stk;
    for (const char num1 : num)
    {
        while (!stk.empty() && stk.back() < num1 && k)
        {
            // cout << "k:" << k << '\n';
            // cout << "pop_back:" << stk.back() << '\n';
            stk.pop_back();
            k--;
        }
        // cout << "push_back:" << num1 << '\n';
        stk.push_back(num1);
    }
    while (k--)
    {
        stk.pop_back();
    }
    for (const char stk1 : stk)
    {
        cout << stk1;
    }
}
