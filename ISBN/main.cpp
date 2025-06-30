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
            location = i+1;
            continue;
        }
        sum += (input[i] - '0') * (i % 2 == 0 ? 1 : 3);
    }

    cout << ((10 - sum % 10) % 10) / (location % 2 == 0 ? 3 : 1);

    return 0;
}
