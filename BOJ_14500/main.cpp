// Problem: 테트로미노
// URL: https://www.acmicpc.net/problem/14500
// Time Limit: 2000 ms
// Memory Limit: 512 MB

/*
문제:
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.정사각형은 서로 겹치면 안 된다.도형은 모두 연결되어 있어야 한다.정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력:
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력:
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

알고리즘 분류:
구현, 브루트포스 알고리즘
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};
vector<vector<int>> paper;
int n, m;
int max_sum = 0;

void dfs(vector<vector<bool>>& visit, const int depth, const int sum, const int x, const int y)
{
    if (depth == 4)
    {
        max_sum = max(max_sum, sum);
        return;
    }
    visit[x][y] = true;
    for (int direction = 0; direction < 4; ++direction)
    {
        const int next_x = x + dx[direction];
        const int next_y = y + dy[direction];
        if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > m - 1)
        {
            continue;
        }
        if (!visit[next_x][next_y])
        {
            dfs(visit, depth + 1, sum + paper[next_x][next_y], next_x, next_y);
        }
    }
    visit[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    paper.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> paper[i][j];
        }
    }

    vector visit1(n, vector<bool>(m));
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < m; ++y)
        {
            // vector visit1(n, vector<bool>(m));
            dfs(visit1, 1, paper[x][y], x, y);

            int sum = paper[x][y];
            int cnt = 1, min_num = 1000;
            for (int direction = 0; direction < 4; ++direction)
            {
                const int next_x = x + dx[direction];
                const int next_y = y + dy[direction];
                if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > m - 1)
                {
                    continue;
                }
                min_num = min(min_num, paper[next_x][next_y]);
                sum += paper[next_x][next_y];
                cnt++;
            }
            if (cnt == 5)
            {
                sum -= min_num;
            }
            max_sum = max(sum, max_sum);
        }
    }

    cout << max_sum;
}
