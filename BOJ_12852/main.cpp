// Problem: 1로 만들기 2
// URL: https://www.acmicpc.net/problem/12852
// Time Limit: 500
// Memory Limit: 512

/*
문제:
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.X가 3으로 나누어 떨어지면, 3으로 나눈다.X가 2로 나누어 떨어지면, 2로 나눈다.1을 뺀다.정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력:
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.

출력:
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력한다. 정답이 여러 가지인 경우에는 아무거나 출력한다.

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

    int n;
    cin >> n;
    vector<int> route(n + 1);
    vector visit(n + 1, -1);

    queue<int> q;
    q.push(n);
    visit[n] = 0;
    while (!q.empty())
    {
        const auto curr = q.front();
        q.pop();

        if (curr % 3 == 0 && visit[curr / 3] == -1)
        {
            visit[curr / 3] = visit[curr] + 1;
            route[curr / 3] = curr;
            q.push(curr / 3);
        }
        if (curr % 2 == 0 && visit[curr / 2] == -1)
        {
            visit[curr / 2] = visit[curr] + 1;
            route[curr / 2] = curr;
            q.push(curr / 2);
        }
        if (curr - 1 >= 1 && visit[curr - 1] == -1)
        {
            visit[curr - 1] = visit[curr] + 1;
            route[curr - 1] = curr;
            q.push(curr - 1);
        }
    }

    cout << visit[1] << '\n';

    vector<int> stk;
    int node = 1;
    while (node)
    {
        stk.push_back(node);
        node = route[node];
    }
    for (int i = stk.size() - 1; i >= 0; --i)
    {
        cout << stk[i] << " ";
    }
}
