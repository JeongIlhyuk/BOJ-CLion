// Problem: 소트
// URL: https://www.acmicpc.net/problem/1083
// Time Limit: 2000
// Memory Limit: 128

/*
문제:
크기가 N인 배열 A가 있다. 배열에 있는 모든 수는 서로 다르다. 이 배열을 소트할 때, 연속된 두 개의 원소만 교환할 수 있다. 그리고, 교환은 많아봐야 S번 할 수 있다. 이때, 소트한 결과가 사전순으로 가장 뒷서는 것을 출력한다.

입력:
첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 각 원소가 차례대로 주어진다. 이 값은 1000000보다 작거나 같은 자연수이다. 마지막 줄에는 S가 주어진다. S는 1000000보다 작거나 같은 음이 아닌 정수이다.

출력:
첫째 줄에 문제의 정답을 출력한다.

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

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int s;
    cin >> s;
    int prev = 0, max_idx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s > 0)
        {
            if (arr[i] > arr[max_idx])
            {
                max_idx = i;
            }
            if (i - prev >= s)
            {
                sort(arr.begin() + prev, arr.begin() + max_idx + 1, greater<int>());
                s -= max_idx - prev;
                prev = max_idx + 1;
                max_idx = i + 1;
            }
        }
    }

    for (const int arr1 : arr)
    {
        cout << arr1 << " ";
    }
}
