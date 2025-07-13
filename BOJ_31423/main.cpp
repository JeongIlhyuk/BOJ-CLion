// Problem: 신촌 통폐합 계획
// URL: https://www.acmicpc.net/problem/31423
// Time Limit: 2000
// Memory Limit: 1024

/*
문제:
극단적인 출산율 감소로 인해 신촌 지역 $N$개 대학교가 하나의 학교로 통합되었다.기나긴 회의 끝에, 통합된 학교의 이름은 $N$개 대학교의 이름을 이어 붙여서 정해졌다. 회의에서 통합된 학교의 이름을 정한 방법은 다음과 같다.$N$개 대학교의 이름 $s_1, s_2, \cdots, s_N$을 일렬로 나열한다. 이후 다음의 과정을 $N - 1$번 반복한다.$s_i, s_j$가 빈 문자열이 아닌 서로 다른 두 정수 $i, j$를 고른다.$s_i$의 뒤쪽에 $s_j$를 이어 붙인다.$s_j$를 빈 문자열로 바꾼다.모든 과정이 끝난 뒤에는 빈 문자열이 아닌 $s_k$가 하나 남게 되며, 이때 $s_k$가 통합된 학교의 이름이 된다.$N$개 대학교의 이름 $s_1, s_2, \cdots, s_N$과 회의에서 고른 $i, j$가 순서대로 주어질 때, 회의를 통해 정해진 통합된 학교의 이름을 구하는 프로그램을 작성해 보자.

입력:
첫 번째 줄에 대학교의 개수 $N$이 주어진다. $(2 \leq N \leq 500 \, 000)$다음 $N$개의 줄의 $i$번째 줄에 대학교 이름을 의미하는 알파벳 소문자로 이루어진 문자열 $s_i$가 주어진다. 주어지는 대학교 이름의 길이 합은 $500\,000$을 넘지 않는다.다음 $N - 1$개의 줄에 회의에서 고른 $i, j$가 공백을 사이에 두고 차례로 주어진다. $(1 \leq i, j \leq N;$ $i \neq j)$주어지는 순서대로 회의를 진행할 때 $s_i, s_j$가 빈 문자열이 아닌 $i, j$만 입력으로 주어진다.

출력:
첫 번째 줄에 회의를 통해 정해진 통합된 학교의 이름을 출력한다.

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

vector<bool> visit;
vector<string> names;
vector<vector<int>> graph;

void dfs(const int u)
{
    cout << names[u];
    visit[u] = true;
    for (const auto v : graph[u])
    {
        if (visit[v])
        {
            continue;
        }
        dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    visit.resize(n + 1);
    names.resize(n + 1);
    graph.resize(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i)
    {
        cin >> names[i];
    }

    int s = 1;
    for (int k = 0; k < n - 1; ++k)
    {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        s = i;
    }
    dfs(s);
}
