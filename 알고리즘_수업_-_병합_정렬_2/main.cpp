// Problem: 알고리즘 수업 - 병합 정렬 2
// URL: https://www.acmicpc.net/problem/24061
// Time Limit: 1000 ms
// Memory Limit: 512 MB

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, c, cnt = 0;
vector<int> arr;

void merge(const int start, const int end)
{
    const int mid = (start + end) / 2;
    int i = start, k = 0, j = mid + 1;
    vector<int> tmp(end - start + 1);

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            tmp[k] = arr[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= end)
    {
        tmp[k++] = arr[j++];
    }

    i = start;
    k = 0;
    while (i <= end)
    {
        arr[i++] = tmp[k++];
        if (++cnt == c)
        {
            for (const auto a : arr)
                cout << a << " ";
            exit(0);
        }
    }
}

void merge_sort(const int start = 0, const int end = n - 1)
{
    if (start >= end)
    {
        return;
    }

    const int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    merge_sort();

    cout << -1;
}
