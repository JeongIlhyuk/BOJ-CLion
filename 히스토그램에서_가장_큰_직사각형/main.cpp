// Problem: 히스토그램에서 가장 큰 직사각형
// URL: https://www.acmicpc.net/problem/6549
// Time Limit: 1000 ms
// Memory Limit: 256 MB

/*
문제:
히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력:
입력은 테스트 케이스 여러 개로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 그 다음 n개의 정수 h1, ..., hn(0 ≤ hi≤ 1,000,000,000)가 주어진다. 이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다. 모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력:
각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다.

알고리즘 분류:
자료 구조, 세그먼트 트리, 분할 정복, 스택
*/

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
    while ((cin >> n) && n)
    {
        stack<int> idx_stack;
        vector<long long> height(n);
        vector<long long> width(n);
        long long max_area = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> height[i];
            long long w = 1;
            while (!idx_stack.empty() && height[i] < height[idx_stack.top()])
            {
                const auto top_idx = idx_stack.top();
                max_area = max(max_area, (w++) * height[top_idx]);
                idx_stack.pop();
            }
            width[i] = w;
            if (!idx_stack.empty())
            {
                const auto top_idx = idx_stack.top();
                if (height[top_idx] == height[i])
                {
                    width[i] += width[top_idx];
                }
                max_area = max(max_area, width[i] * height[i]);
            }
            // cout << "width:" << width[i] << ' ';
            idx_stack.push(i);
        }

        long long w = 1;
        while (!idx_stack.empty())
        {
            // cout << "stack size: " << idx_stack.size() << endl;
            const auto top_idx = idx_stack.top();
            // cout << "top_idx: " << top_idx << ", height: " << height[top_idx] << ", w: " << w << endl;
            max_area = max(max_area, (w++) * height[top_idx]);
            // cout << "After calculation, about to pop" << endl;
            idx_stack.pop();
            // cout << "Popped successfully" << endl;
        }

        for (const int w : width)
        {
            cout << " w:" << w;
        }
        cout << '\n';
        for (const int h : height)
        {
            cout << " h:" << h;
        }
        cout << '\n';

        // max_area = max(max_area, width[idx_stack.top()] * height[idx_stack.top()]);
        cout << max_area << '\n';
    }
}
