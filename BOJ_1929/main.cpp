// Problem: 소수 구하기
// URL: https://www.acmicpc.net/problem/1929
// Time Limit: 2000
// Memory Limit: 256

/*
문제:
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력:
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력:
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

알고리즘 분류:
N/A
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (!prime[i])
        {
            continue;
        }
        for (long long k = static_cast<long long>(i) * i; k <= n; k += i)
        {
            prime[k] = false;
        }
    }

    for (int i = m; i <= n; ++i)
    {
        if (!prime[i])
        {
            continue;
        }
        cout << i << '\n';
    }
}
