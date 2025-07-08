// Problem: N과 M (9)
// URL: https://www.acmicpc.net/problem/15663
// Time Limit: 1000 ms
// Memory Limit: 512 MB

/*
문제:
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.N개의 자연수 중에서 M개를 고른 수열

입력:
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력:
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.수열은 사전 순으로 증가하는 순서로 출력해야 한다.

알고리즘 분류:
백트래킹
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<bool> visit;
vector<int> result;
int n, m;

void go(const int idx, const int depth)
{
    // cout << "n:" << n << '\n';
    // cout << "m:" << m << '\n';
    // cout << "idx:" << idx << '\n';
    // cout << "depth:" << depth << '\n';
    if (depth == m)
    {
        for (const int& result1 : result)
        {
            cout << result1 << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (visit[i] || (i - 1 >= 0 && !visit[i - 1] && arr[i - 1] == arr[i]))
        {
            continue;
        }
        visit[i] = true;
        result[depth] = arr[i];
        go(i, depth + 1);
        visit[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.resize(n);
    visit.resize(n);
    result.resize(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    go(-1, 0);
}
