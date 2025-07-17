// Problem: 팩토리얼 0의 개수
// URL: https://www.acmicpc.net/problem/1676
// Time Limit: 2000
// Memory Limit: 128

/*
문제:
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력:
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력:
첫째 줄에 구한 0의 개수를 출력한다.

알고리즘 분류:
수학
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

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            cnt1++;
        }
        if (i % 5 == 0)
        {
            cnt2++;
        }
    }
    cout << min(cnt1, cnt2);
}
