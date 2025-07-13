// Problem: 나머지 합
// URL: https://www.acmicpc.net/problem/10986
// Time Limit: 1000
// Memory Limit: 256

/*
문제:
수 N개 A1, A2, ..., AN이 주어진다. 이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.즉, Ai+ ... + Aj(i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.

입력:
첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 106, 2 ≤ M ≤ 103)둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai≤ 109)

출력:
첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.

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

    int n, m;
    cin >> n >> m;
    vector<long long> arr(n + 1);
    vector<int> mod(m);
    mod[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        arr[i] = num + arr[i - 1];
        // cout << "arr[" << i << "]:" << arr[i] << '\n';
        mod[arr[i] % m]++;
    }
    // cout << '\n';

    long long result = 0;
    for (int i = 0; i < m; ++i)
    {
        // cout << "mod[" << i << "]:" << mod[i] << '\n';
        result += static_cast<long long>(mod[i]) * (mod[i] - 1) / 2;
    }

    cout << result;
}
