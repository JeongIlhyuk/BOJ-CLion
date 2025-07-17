// Problem: 방벽 게임
// URL: https://www.acmicpc.net/problem/32714
// Time Limit: 1000
// Memory Limit: 1024

/*
문제:
건덕이와 건구스는 $N$행 $2$열의 칸으로 이루어진 전장에서 승부를 겨루고 있다. 건덕이는 $1$행 $1$열에서 시작하여 말을 $N$행까지 이동해야 한다. 건구스는 칸과 칸 사이에 방벽을 설치하여 건덕이를 저지할 수 있다.게임은 아래의 순서로 건덕이의 말이 $N$행에 도달할 때까지 반복된다.건덕이가 말을 상하좌우로 인접한 칸으로 이동한다. 단, 현재 위치한 칸과 이동하려는 칸 사이에 방벽이 있는 경우 해당 칸으로 이동할 수 없다.건구스가 게임판 내에서 가로 또는 세로로 연속하는 두 칸을 선택하여 그 사이에 방벽을 설치한다. 단, 건덕이가 $N$행에 도달할 수 없게 막아버리면 안 된다. 조건에 맞게 방벽을 설치할 수 없거나 설치하고 싶지 않다면 차례를 넘길 수 있다.건덕이는 말을 최대한 빨리, 건구스는 최대한 늦게 $N$행에 도달하게 하고자 한다. 모두가 최선을 다할 때, 말이 $N$행에 도달하기 위한 이동 횟수를 구해보자.

입력:
첫째 줄에 격자의 행 수 $N$이 주어진다. $\left(2 \leq N \leq 1,000,000\right)$

출력:
말이 $N$행에 도달하기 위한 이동 횟수를 출력한다.

알고리즘 분류:
애드 혹, 게임 이론
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
    // vector dp(n + 1, vector<int>(2));
    //
    // for (int i = 1; i <= n; ++i)
    // {
    //     dp[i][0];
    // }
    if (n == 2)
    {
        cout << 1;
        return 0;
    }
    if (n == 3)
    {
        cout << 3;
        return 0;
    }
    cout << ((n - 2) * 2 + n);
}
