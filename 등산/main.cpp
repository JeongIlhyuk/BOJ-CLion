// Problem: 등산
// URL: https://www.acmicpc.net/problem/1486
// Time Limit: 2000 ms
// Memory Limit: 128 MB

#include <iostream>
#include <vector>

#define DIRECTION 4
#define INF 51*51+1

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t, d;
    cin >> n >> m >> t >> d;

    const int SIZE = n * m;

    vector<int> map(SIZE);
    vector adj(SIZE, vector(SIZE, INF));

    for (int i = 0; i < SIZE; ++i)
        adj[i][i] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            const int idx = i * m + j;
            char input;
            cin >> input;
            if (input < 'a') map[idx] = input - 'A';
            else map[idx] = input - 'a' + 26;
        }
    }

    for (int i = 0; i < SIZE; ++i)
    {
        const int x = i / m;
        const int y = i % m;
        for (int j = 0; j < DIRECTION; ++j)
        {
            constexpr int dx[DIRECTION] = {-1, 1, 0, 0};
            constexpr int dy[DIRECTION] = {0, 0, -1, 1};
            const int nx = x + dx[j];
            const int ny = y + dy[j];
            const int ni = nx * m + ny;

            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if (map[ni] - map[i] > t || map[ni] - map[i] < -t) continue;

            if (map[ni] > map[i])adj[i][ni] = (map[ni] - map[i]) * (map[ni] - map[i]);
            else adj[i][ni] = 1;
        }
    }

    for (int k = 0; k < SIZE; ++k)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j]) adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    int result = map[0];
    for (int i = 1; i < SIZE; ++i)
        if (adj[0][i] + adj[i][0] <= d && map[i] > result)result = map[i];
    cout << result;

    return 0;
}
