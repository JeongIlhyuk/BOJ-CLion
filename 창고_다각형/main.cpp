// Problem: 창고 다각형
// URL: https://www.acmicpc.net/problem/2304
// Time Limit: 2000 ms
// Memory Limit: 128 MB

/*
문제:
N 개의 막대 기둥이 일렬로 세워져 있다. 기둥들의 폭은 모두 1 m이며 높이는 다를 수 있다. 이 기둥들을 이용하여 양철로 된 창고를 제작하려고 한다. 창고에는 모든 기둥이 들어간다. 이 창고의 지붕을 다음과 같이 만든다.지붕은 수평 부분과 수직 부분으로 구성되며, 모두 연결되어야 한다.지붕의 수평 부분은 반드시 어떤 기둥의 윗면과 닿아야 한다.지붕의 수직 부분은 반드시 어떤 기둥의 옆면과 닿아야 한다.지붕의 가장자리는 땅에 닿아야 한다.비가 올 때 물이 고이지 않도록 지붕의 어떤 부분도 오목하게 들어간 부분이 없어야 한다.그림 1은 창고를 옆에서 본 모습을 그린 것이다. 이 그림에서 굵은 선으로 표시된 부분이 지붕에 해당되고, 지붕과 땅으로 둘러싸인 다각형이 창고를 옆에서 본 모습이다. 이 다각형을 창고 다각형이라고 하자.그림1 . 기둥과 지붕(굵은 선)의 예창고 주인은 창고 다각형의 면적이 가장 작은 창고를 만들기를 원한다. 그림 1에서 창고 다각형의 면적은 98 ㎡이고, 이 경우가 가장 작은 창고 다각형이다.기둥들의 위치와 높이가 주어질 때, 가장 작은 창고 다각형의 면적을 구하는 프로그램을 작성하시오.

입력:
첫 줄에는 기둥의 개수를 나타내는 정수 N이 주어진다. N은 1 이상 1,000 이하이다. 그 다음 N 개의 줄에는 각 줄에 각 기둥의 왼쪽 면의 위치를 나타내는 정수 L과 높이를 나타내는 정수 H가 한 개의 빈 칸을 사이에 두고 주어진다. L과 H는 둘 다 1 이상 1,000 이하이다.

출력:
첫 줄에 창고 다각형의 면적을 나타내는 정수를 출력한다.

알고리즘 분류:
구현, 자료 구조, 브루트포스 알고리즘, 스택
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <bit>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    stack<int> s;
    int highest_idx = 0;
    for (int i = 0; i < n; ++i)
    {
        int l, h;
        cin >> l >> h;
        arr[i] = {l, h};

        if (h > arr[highest_idx].second)
        {
            highest_idx = i;
        }
    }
    ranges::sort(arr);

    for (int i = highest_idx; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()].second <= arr[i].second)
        {
            s.pop();
        }
        s.push(i);
    }
    int area = 0;
    while (!s.empty() && s.top() < highest_idx)
    {
        const auto top_idx = s.top();
        s.pop();
        while (arr[s.top()].second <= arr[top_idx].second)
        {
            s.pop();
        }
        area += (arr[s.top()].first - arr[top_idx].first) * arr[top_idx].second;
    }

    for (int i = highest_idx; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()].second <= arr[i].second)
        {
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty() && s.top() > highest_idx)
    {
        const auto top_idx = s.top();
        s.pop();
        while (arr[s.top()].second <= arr[top_idx].second)
        {
            s.pop();
        }
        area += (arr[top_idx].first - arr[s.top()].first) * arr[top_idx].second;
    }

    cout << area;
}
