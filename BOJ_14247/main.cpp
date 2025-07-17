// Problem: 나무 자르기
// URL: https://www.acmicpc.net/problem/14247
// Time Limit: 2000
// Memory Limit: 512

/*
문제:
영선이는 나무꾼으로 나무를 구하러 오전에 산에 오른다. 산에는 $n$개의 나무가 있는데, 영선이는 하루에 한 나무씩 $n$일 산에 오르며 나무를 잘라갈 것이다. 하지만 이 산은 영험한 기운이 있어 나무들이 밤만 되면 매우 빠른 속도로 자라는데, 그 자라는 길이는 나무마다 다르다.따라서, 어느 나무를 먼저 잘라가느냐에 따라서 총 구할 수 있는 나무의 양이 다른데,나무의 처음 길이와 하루에 자라는 양이 주어졌을 때, 영선이가 얻을 수 있는 최대 나무양을 구하시오.참고로, 자른 이후에도 나무는 $0$부터 다시 자라기 때문에 같은 나무를 여러 번 자를 수는 있다.

입력:
첫째 줄에는 나무의 개수 $n$개가 있다. 나무는 $1$번부터 $n$번까지 있다.다음 줄에는 첫날 올라갔을 때 나무의 길이들 $H_i$가 $n$개가 순서대로 주어진다.그 다음 줄에는 나무들이 자라는 길이 $A_i$가 $n$개가 순서대로 주어진다.

출력:
영선이가 나무를 잘라서 구할 수 있는 최대 양을 출력하시오.

알고리즘 분류:
그리디 알고리즘, 정렬
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> H(n), A(n);
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> trees;
    for (int i = 0; i < n; i++) {
        trees.emplace_back(A[i], H[i]);
    }
    sort(trees.begin(), trees.end());

    long long total = 0;
    for (int day = 0; day < n; day++) {
        total += trees[day].second + static_cast<long long>(trees[day].first) * day;
    }

    cout << total << "\n";
    return 0;
}