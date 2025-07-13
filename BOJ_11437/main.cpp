// Problem: LCA
// URL: https://www.acmicpc.net/problem/11437
// Time Limit: 3000
// Memory Limit: 256

/*
문제:
N(2 ≤ N ≤ 50,000)개의 정점으로 이루어진 트리가 주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.두 노드의 쌍 M(1 ≤ M ≤ 10,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.

입력:
첫째 줄에 노드의 개수 N이 주어지고, 다음 N-1개 줄에는 트리 상에서 연결된 두 정점이 주어진다. 그 다음 줄에는 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M이 주어지고, 다음 M개 줄에는 정점 쌍이 주어진다.

출력:
M개의 줄에 차례대로 입력받은 두 정점의 가장 가까운 공통 조상을 출력한다.

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

int n;
constexpr int LOGN = 16;
vector<int> depth;
vector<vector<int>> graph;
vector<vector<int>> parent;

void dfs(const int d, const int p, const int v)
{
    depth[v] = d;
    parent[v][0] = p;
    for (const int child : graph[v])
    {
        if (child == p)
        {
            continue;
        }
        dfs(d + 1, v, child);
    }
}

void preprocess()
{
    for (int j = 1; j < LOGN; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (parent[i][j - 1] == -1)
            {
                continue;
            }
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }

    const int diff = depth[u] - depth[v];
    for (int i = 0; i < LOGN; ++i)
    {
        if ((diff >> i) & 1)
        {
            u = parent[u][i];
        }
    }

    if (u == v)
    {
        return u;
    }

    for (int i = LOGN - 1; i >= 0; --i)
    {
        if (parent[u][i] == parent[v][i])
        {
            continue;
        }
        u = parent[u][i];
        v = parent[v][i];
    }

    return parent[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    graph.resize(n + 1);
    depth.resize(n + 1);
    parent.resize(n + 1, vector(LOGN, -1));

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, -1, 1);
    preprocess();

    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}
