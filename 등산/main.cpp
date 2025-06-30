// Problem: 등산
// URL: https://www.acmicpc.net/problem/1486
// Time Limit: 2000 ms
// Memory Limit: 128 MB

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t, d;
    cin >> n >> m >> t >> d;

    const int SIZE = n * m;

    vector<int> map(SIZE);
    vector<vector<int>> adj(SIZE, vector<int>(SIZE, 51 * 51 + 1));

    for (int i = 0; i < SIZE; ++i)
        adj[i][i] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> map[i * n + j];
            if (map[i * n + j] < 'a') map[i * n + j] -= 'A';
            else map[i * n + j] -= 'a' - 26;
        }
    }

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    for (int i = 0; i < SIZE; ++i)
    {
        const int x = i / n;
        const int y = i % n;
        for (int j = 0; j < 4; ++j)
        {
            const int nx = x + dx[j];
            const int ny = y + dy[j];
            const int ni = nx * n + ny;
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if (map[ni] - map[i] <= t && map[ni] - map[i] >= -t)
            {
                if (map[ni] > map[i])adj[i][ni] = (map[ni] - map[i]) * (map[ni] - map[i]);
                else adj[i][ni] = 1;
            }
        }
    }

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < SIZE; ++k)
            {
                if (adj[j][i] + adj[i][k] < adj[j][k]) adj[j][k] = adj[j][i] + adj[i][k];
            }
        }
    }

    int result=0;
    for (int i = 0; i < SIZE; ++i)
    {
        if (adj[0][i]+adj[i][0]<=d && map[i]>result)
        {
            result=map[i];
        }
    }
    cout<<result;

    return 0;
}
