// Problem: 도로포장
// URL: https://www.acmicpc.net/problem/1162
// Time Limit: 2000 ms
// Memory Limit: 128 MB

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector edges(n+1, vector<int>(n+1));

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u][v]=w;
        edges[v][u]=w;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (edges[i][j])
            {

            }
        }
    }

    return 0;
}
