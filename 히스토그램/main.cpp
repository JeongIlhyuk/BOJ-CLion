// Problem: 히스토그램
// URL: https://www.acmicpc.net/problem/1725
// Time Limit: 700 ms
// Memory Limit: 128 MB

/*
문제:
히스토그램에 대해서 알고 있는가? 히스토그램은 아래와 같은 막대그래프를 말한다.각 칸의 간격은 일정하고, 높이는 어떤 정수로 주어진다. 위 그림의 경우 높이가 각각 2 1 4 5 1 3 3이다.이러한 히스토그램의 내부에 가장 넓이가 큰 직사각형을 그리려고 한다. 아래 그림의 빗금 친 부분이 그 예이다. 이 직사각형의 밑변은 항상 히스토그램의 아랫변에 평행하게 그려져야 한다.주어진 히스토그램에 대해, 가장 큰 직사각형의 넓이를 구하는 프로그램을 작성하시오.

입력:
첫 행에는 N (1 ≤ N ≤ 100,000) 이 주어진다. N은 히스토그램의 가로 칸의 수이다. 다음 N 행에 걸쳐 각 칸의 높이가 왼쪽에서부터 차례대로 주어진다. 각 칸의 높이는 1,000,000,000보다 작거나 같은 자연수 또는 0이다.

출력:
첫째 줄에 가장 큰 직사각형의 넓이를 출력한다. 이 값은 20억을 넘지 않는다.

알고리즘 분류:
자료 구조, 세그먼트 트리, 분할 정복, 스택
*/

#include <iostream>
#include <vector>
#include <bit>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n) {
        vector<long long> height(n);
        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }

        stack<int> st;
        long long max_area = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] > height[i]) {
                long long h = height[st.top()];
                st.pop();
                long long w = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, h * w);
            }
            st.push(i);
        }

        while (!st.empty()) {
            long long h = height[st.top()];
            st.pop();
            long long w = st.empty() ? n : n - st.top() - 1;
            max_area = max(max_area, h * w);
        }

        cout << max_area << '\n';
    }
}
