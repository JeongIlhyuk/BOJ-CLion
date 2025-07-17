// Problem: 내리막 길
// URL: https://www.acmicpc.net/problem/1520
// Time Limit: 2000
// Memory Limit: 128

/*
문제:
여행을 떠난 세준이는 지도를 하나 구하였다. 이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 세준이는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다. 그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다. 위와 같은 지도에서는 다음과 같은 세 가지 경로가 가능하다.지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.

입력:
첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 N이 빈칸을 사이에 두고 주어진다. 이어 다음 M개 줄에 걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 빈 칸을 사이에 두고 주어진다. M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수이다.

출력:
첫째 줄에 이동 가능한 경로의 수 H를 출력한다. 모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.

알고리즘 분류:
다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 깊이 우선 탐색, 격자 그래프
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int m, n, cnt = 0;
vector<vector<int>> _map;
vector<vector<bool>> visit;

void dfs(const int x, const int y)
{
    if (x == m - 1 && y == n - 1)
    {
        cnt++;
        return;
    }
    visit[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        const int nx = x + dx[i];
        const int ny = y + dy[i];
        if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || visit[nx][ny] || _map[nx][ny] >= _map[x][y])
        {
            continue;
        }
        dfs(nx, ny);
    }
    visit[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    _map.resize(m, vector<int>(n));
    visit.resize(m, vector<bool>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> _map[i][j];
        }
    }
    dfs(0, 0);

    cout << cnt;
}
