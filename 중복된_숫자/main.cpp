// Problem: 중복된 숫자
// URL: https://www.acmicpc.net/problem/15719
// Time Limit: 2000 ms
// Memory Limit: 256 MB

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<bool> arr(n+1);

    while (n--)
    {
        int input;
        cin>>input;
        if (arr[input])
        {
            cout<<input;
            return 0;
        }
        arr[input]=true;
    }

    return 0;
}
