// Problem: 최소비용 구하기 2
// URL: https://www.acmicpc.net/problem/11779
// Time Limit: 1000
// Memory Limit: 256

/*
문제:
n(1≤n≤1,000)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라. 항상 시작점에서 도착점으로의 경로가 존재한다.

입력:
첫째 줄에 도시의 개수 n(1≤n≤1,000)이 주어지고 둘째 줄에는 버스의 개수 m(1≤m≤100,000)이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.그리고 m+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다.

출력:
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.둘째 줄에는 그러한 최소 비용을 갖는 경로에 포함되어있는 도시의 개수를 출력한다. 출발 도시와 도착 도시도 포함한다.셋째 줄에는 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력한다. 경로가 여러가지인 경우 아무거나 하나 출력한다.

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

    int n, m;
    cin >> n >> m;
    vector graph(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    int s, e;
    cin >> s >> e;

    vector<long long> dist(n + 1, 1e12);
    vector<int> route(n + 1);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        const auto [weight,curr] = pq.top();
        pq.pop();

        if (weight > dist[curr])
        {
            continue;
        }

        for (const auto& [w,next] : graph[curr])
        {
            if (dist[curr] + w >= dist[next])
            {
                continue;
            }
            dist[next] = dist[curr] + w;
            route[next] = curr;
            pq.push({dist[next], next});
        }
    }

    cout << dist[e] << '\n';
    int node = e, cnt = 0;;
    vector<int> stk;
    while (node)
    {
        cnt++;
        stk.push_back(node);
        node = route[node];
    }

    cout << cnt << '\n';
    for (int i = stk.size() - 1; i >= 0; --i)
    {
        cout << stk[i] << " ";
    }
}
