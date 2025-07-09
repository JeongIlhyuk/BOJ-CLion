// Problem: Strongly Connected Component
// URL: https://www.acmicpc.net/problem/2150
// Time Limit: 2000
// Memory Limit: 128

/*
문제:
N/A

입력:
N/A

출력:
N/A

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

vector<int> dfs_num;
vector<vector<int>> graph;
vector<int> low;
vector<bool> on_stack;

vector<vector<int>> sccs;
vector<int> stk;
int dfs_cnt = 0;

void tarjan(const int v)
{
    dfs_num[v] = low[v] = dfs_cnt++;
    on_stack[v] = true;
    stk.push_back(v);

    for (const int next : graph[v])
    {
        if (dfs_num[next] == -1)
        {
            tarjan(next);
            low[v] = min(low[v], low[next]);
        }
        else if (on_stack[next])
        {
            low[v] = min(low[v], low[next]);
        }
    }

    if (dfs_num[v] == low[v])
    {
        vector<int> scc;
        while (!stk.empty())
        {
            int node = stk.back();
            stk.pop_back();
            on_stack[node] = false;
            scc.push_back(node);
            // if (node == v)break;
        }
        sort(scc.begin(), scc.end());
        sccs.push_back(scc);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    dfs_num.resize(v + 1, -1);
    graph.resize(v + 1);
    low.resize(v + 1, -1);
    on_stack.resize(v + 1);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= v; ++i)
    {
        if (dfs_num[i] != -1)
        {
            continue;
        }
        tarjan(i);
    }
    if (sccs.size() == 0)
    {
        cout << "Fuck!";
        return 0;
    }
    cout << sccs.size() << '\n';
    // sort(sccs.begin(), sccs.end(), [](const vector<int>& scc1, const vector<int>& scc2)
    // {
    //     return scc1.front() < scc2.front();
    // });
    for (const auto& scc : sccs)
    {
        for (const auto scc1 : scc)
        {
            cout << scc1 << " ";
        }
        cout << -1 << '\n';
    }
}
