// Problem: 스타트와 링크
// URL: https://www.acmicpc.net/problem/14889
// Time Limit: 2000 ms
// Memory Limit: 512 MB

#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;


int n, result = INF;
vector<vector<int>> vec;
vector<int> team;

void go(const int idx = 0, const int cnt = 0)
{
    if (cnt == n / 2)
    {
        int sum0 = 0, sum1 = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (team[i] == 0 && team[j] == 0)sum0 += vec[i][j];
                if (team[i] == 1 && team[j] == 1)sum1 += vec[i][j];
            }
        result = min(result, (sum0 < sum1 ? sum1 - sum0 : sum0 - sum1));
        return;
    }
    if (idx == n - 1) return;

    team[idx + 1] = 1;
    go(idx + 1, cnt + 1);
    team[idx + 1] = 0;
    go(idx + 1, cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vec.resize(n, vector<int>(n));
    team.resize(n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> vec[i][j];

    go();

    cout << result;

    return 0;
}
