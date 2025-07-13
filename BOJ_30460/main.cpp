// Problem: 스위치
// URL: https://www.acmicpc.net/problem/30460
// Time Limit: 1000
// Memory Limit: 1024

/*
문제:
$i$초에 $A_i$의 점수를 얻는 게임이 있다. $N$초 동안 진행하는 이 게임에서는 점수를 추가로 얻기 위해 $T$초에 스위치를 눌러 $T,T+1,T+2$초에 얻는 점수를 $2$배로 만들 수 있다. $T$초에 스위치를 누르면 $T+3$초부터 다시 스위치를 누를 수 있다.게임이 진행되는 동안 스위치를 적절하게 눌렀을 때 얻을 수 있는 점수의 최댓값을 구해보자.

입력:
첫째 줄에 점수를 얻는 횟수 $N$이 주어진다. $\left( 3\leq N\leq 200\, 000 \right)$둘째 줄에 $i$초에 얻는 점수를 나타내는 정수 $A_i$가 공백으로 구분되어 주어진다. $\left( 1\leq i\leq N;\ |A_i|\leq 1\, 000 \right)$

출력:
얻을 수 있는 점수의 최댓값을 출력한다.

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
}
