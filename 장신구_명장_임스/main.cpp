// Problem: 장신구 명장 임스
// URL: https://www.acmicpc.net/problem/25496
// Time Limit: 1000 ms
// Memory Limit: 1024 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, n;
    cin >> p >> n;

    int arr[n];

    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    int result=0;
    for (int i=0;i<n;i++)
    {
        if (p>=200)break;
        p+=arr[i];
        result++;
    }

    cout<<result;

    return 0;
}
