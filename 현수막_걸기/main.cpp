// Problem: 현수막 걸기
// URL: https://www.acmicpc.net/problem/30459
// Time Limit: 1000 ms
// Memory Limit: 1024 MB

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> ground(n);
    vector<int> flag(m);

    for (int i = 0; i < n; i++)
    {
        cin >> ground[i];
    }
    sort(ground.begin(), ground.end());

    for (int i = 0; i < m; i++)
    {
        cin >> flag[i];
    }
    sort(flag.begin(), flag.end());

    int result = -1;
    for (int diff = 1; diff <= n - 1; ++diff)
    {
        for (int i = 0; i < n - diff; ++i)
        {
            const int width = ground[i + diff] - ground[i];
            int low = 0, high = m - 1;
            while (low <= high)
            {
                const int mid = (low + high) / 2;
                const int height = flag[mid];
                const int area = height * width;

                if (area == 2 * r)
                {
                    cout << r << ".0";
                    return 0;
                }
                if (area > 2 * r)
                {
                    high = mid - 1;
                    continue;
                }
                low = mid + 1;
                result = max(result,area);
            }
        }
    }
    if (result==-1)
    {
        cout<<-1;
        return 0;
    }

    cout << result / 2 << (result % 2 == 0 ? ".0" : ".5");
}
