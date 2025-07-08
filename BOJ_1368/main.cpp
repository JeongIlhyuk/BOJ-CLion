// Problem: 물대기
// URL: https://www.acmicpc.net/problem/1368
// Time Limit: 2000 ms
// Memory Limit: 128 MB

/*
문제:
선주는 자신이 운영하는 N개의 논에 물을 대려고 한다. 물을 대는 방법은 두 가지가 있는데 하나는 직접 논에 우물을 파는 것이고 다른 하나는 이미 물을 대고 있는 다른 논으로부터 물을 끌어오는 법이다.각각의 논에 대해 우물을 파는 비용과 논들 사이에 물을 끌어오는 비용들이 주어졌을 때 최소의 비용으로 모든 논에 물을 대는 것이 문제이다.

입력:
첫 줄에는 논의 수 N(1 ≤ N ≤ 300)이 주어진다. 다음 N개의 줄에는 i번째 논에 우물을 팔 때 드는 비용 Wi(1 ≤ Wi ≤ 100,000)가 순서대로 들어온다. 다음 N개의 줄에 대해서는 각 줄에 N개의 수가 들어오는데 이는 i번째 논과 j번째 논을 연결하는데 드는 비용 Pi,j(1 ≤ Pi,j ≤ 100,000, Pi,j = Pj,i, Pi,i = 0)를 의미한다.

출력:
첫 줄에 모든 논에 물을 대는데 필요한 최소비용을 출력한다.

알고리즘 분류:
그래프 이론, 최소 스패닝 트리
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> parent;
vector<int> _rank;

int find(const int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(const int x, const int y)
{
    const int root_x = find(x);
    const int root_y = find(y);
    if (_rank[root_x] > _rank[root_y])
    {
        parent[root_y] = root_x;
        return;
    }
    if (_rank[root_x] < _rank[root_y])
    {
        parent[root_x] = root_y;
        return;
    }

    parent[root_x] = root_y;
    _rank[root_y]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    parent.resize(2 * n);
    for (int i = 0; i < 2 * n; ++i)
    {
        parent[i] = i;
    }

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i)
    {
        int w;
        cin >> w;
        edges.push_back({w, i, i + n});
        edges.push_back({w, i + n, i});
    }

    _rank.resize(2 * n);
    for (int i = n + 1; i < 2 * n; ++i)
    {
        merge(i, i - 1);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int pij;
            cin >> pij;
            if (i == j)
            {
                continue;
            }
            edges.push_back({pij, i, j});
            edges.push_back({pij, j, i});
        }
    }
    sort(edges.begin(), edges.end());

    int result = 0;
    for (const auto& [w,u,v] : edges)
    {
        if (find(u) == find(v))
        {
            continue;
        }
        merge(u, v);
        result += w;
    }

    cout << result;
}