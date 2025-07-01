// Problem: ISBN
// URL: https://www.acmicpc.net/problem/14626
// Time Limit: 1000 ms
// Memory Limit: 128 MB

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = 0, location;
    string input;
    cin >> input;
    for (int i = 0; i < 13; i++)
    {
        if (input[i] == '*')
        {
            location = i;
            continue;
        }
        sum += (input[i] - '0') * (i % 2 == 0 ? 1 : 3);
    }

    const int m = location % 2 == 0 ? 1 : 3;
    for (int i = 0; i < 10; ++i)
    {
        if ((sum + i * m) % 10 == 0)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}
