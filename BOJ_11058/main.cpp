// Problem: 크리보드
// URL: https://www.acmicpc.net/problem/11058
// Time Limit: 1000
// Memory Limit: 256

/*
문제:
크리보드는 kriii가 만든 신기한 키보드이다. 크리보드에는 버튼이 4개만 있으며, 하는 역할은 다음과 같다.화면에 A를 출력한다.Ctrl-A: 화면을 전체 선택한다Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.크리보드의 버튼을 총 N번 눌러서 화면에 출력된 A개수를 최대로하는 프로그램을 작성하시오.

입력:
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력:
크리보드의 버튼을 총 N번 눌러서 화면에 출력할 수 있는 A 개수의 최댓값을 출력한다.

알고리즘 분류:
다이나믹 프로그래밍
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
}