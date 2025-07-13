// Problem: 플로이드 2
// URL: https://www.acmicpc.net/problem/11780
// Time Limit: 1000
// Memory Limit: 256

/*
문제:
n(1 ≤ n ≤ 100)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 각 버스는 한 번 사용할 때 필요한 비용이 있다.모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.

입력:
첫째 줄에 도시의 개수 n이 주어지고 둘째 줄에는 버스의 개수 m이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.

출력:
먼저, n개의 줄을 출력해야 한다. i번째 줄에 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용이다. 만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.그 다음에는 n×n개의 줄을 출력해야 한다. i×n+j번째 줄에는 도시 i에서 도시 j로 가는 최소 비용에 포함되어 있는 도시의 개수 k를 출력한다. 그 다음, 도시 i에서 도시 j로 가는 경로를 공백으로 구분해 출력한다. 이때, 도시 i와 도시 j도 출력해야 한다. 만약, i에서 j로 갈 수 없는 경우에는 0을 출력한다.

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
    vector matrix(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; ++i)
    {
        matrix[i][i] = 0;
    }
    vector route(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a][b] = min(matrix[a][b], c);
        route[a][b] = a;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    route[i][j] = route[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << (matrix[i][j] == 1e9 ? 0 : matrix[i][j]) << " ";
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (matrix[i][j] == 1e9 || i == j)
            {
                cout << 0 << '\n';
                continue;
            }
            int node = j;
            vector<int> stk;
            while (node)
            {
                // cout << "node:" << node << '\n';
                stk.push_back(node);
                node = route[i][node];
            }
            cout << stk.size() << ' ';
            for (int i = stk.size() - 1; i >= 0; --i)
            {
                cout << stk[i] << ' ';;
            }
            cout << '\n';
        }
    }
}
