#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int min_p = 1000, min_s = 1000;
    while (m--)
    {
        int p, s;
        cin >> p >> s;
        min_p = min(min_p, p);
        min_s = min(min_s, s);
    }

    if (min_s * 6 < min_p)
    {
        cout << min_s * n;
        return 0;
    }

    cout << n / 6 * min_p + min(n % 6 * min_s, min_p);
}
