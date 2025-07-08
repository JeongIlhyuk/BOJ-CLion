// Problem: CD
// URL: https://www.acmicpc.net/problem/4158
// Time Limit: 1000 ms
// Memory Limit: 256 MB

/*
문제:
상근이와 선영이는 동시에 가지고 있는 CD를 팔려고 한다. CD를 몇 개나 팔 수 있을까?

입력:
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 상근이가 가지고 있는 CD의 수 N, 선영이가 가지고 있는 CD의 수 M이 주어진다. N과 M은 최대 백만이다. 다음 줄부터 N개 줄에는 상근이가 가지고 있는 CD의 번호가 오름차순으로 주어진다. 다음 M개 줄에는 선영이가 가지고 있는 CD의 번호가 오름차순으로 주어진다. CD의 번호는 십억을 넘지 않는 양의 정수이다. 입력의 마지막 줄에는 0 0이 주어진다.상근이와 선영이가 같은 CD를 여러장 가지고 있는 경우는 없다.

출력:
두 사람이 동시에 가지고 있는 CD의 개수를 출력한다.

알고리즘 분류:
자료 구조, 이분 탐색, 해시를 사용한 집합과 맵, 집합과 맵, 두 포인터
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        int cnt = 0;
        unordered_map<int, bool> um;
        for (int i = 0; i < n; ++i)
        {
            int input;
            cin >> input;
            um[input] = true;
        }
        for (int i = 0; i < m; ++i)
        {
            int input;
            cin >> input;
            if (um[input])
            {
                cnt++;
            }
        }
        cout << cnt<<'\n';
    }
}
