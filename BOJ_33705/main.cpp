// Problem: 마스코트 정하기
// URL: https://www.acmicpc.net/problem/33705
// Time Limit: 1000
// Memory Limit: 1024

/*
문제:
$N$명의 학생들이 건국대학교의 마스코트를 투표하기 위해 모였다!투표를 하려는 건국대학교의 학생들은 $1$번, $2$번, $\cdots$, $N$번 학생이 한 줄로 나란히 서 있다.각 학생은 $1$과 $N$ 사이의 정수 번호를 가지는 $N$ 종류의 마스코트 후보 중 하나에게 투표하려고 한다. $i$번째 학생은 $A_i$번 후보에 투표한다.유력 마스코트 후보인 쿠는 자신이 마스코트가 되기 위해 투표를 하려는 학생들을 쫓아내는 일을 당신에게 맡겼다.당신은 아래의 행동을원하는 만큼반복할 수 있다.$1 \le L \le R \le N$인 두 정수 $L$, $R$을 골라 $L$번, $L + 1$번, $\cdots$, $R - 1$번, $R$번 사람 중 투표장에 남아 있는 학생들을모두투표장에서 내쫓는다.학생들을 내쫓은 이후, 투표장에 최소 $1$명의 학생이 남아있어야 한다. 즉,모든 학생을 내쫓는 것은 불가능하다.투표장에서 내쫓아진 학생들은 투표에 참여할 수 없으며,투표한 학생의 수에 포함되지 않는다.투표한 학생이 $m$명일 때, $\left\lceil\frac{m}{2}\right\rceil$명 이상의 표를 받은모든후보가 마스코트가 된다.학생들을 쫓아내는 행동을 최소 몇 번 하여야 $1$번 마스코트 후보인 쿠가 마스코트가 될 수 있을까?

입력:
첫째 줄에 투표를 하려는 학생의 수 $N$이 주어진다. $\left(1 \le N \le 200\, 000\right)$둘째 줄에 각 학생이 투표하려는 후보의 번호를 나타내는 $N$개의 정수 $A_1,\, A_2,\, \cdots,\, A_N$이 공백으로 구분되어 주어진다. $\left(1 \le A_i \le N\right)$최소 한 명의 학생이 $1$번에 투표했음이 보장된다.

출력:
$1$번 마스코트 후보인 쿠가 마스코트가 되기 위한 최소 행동 횟수를 출력한다.

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
    vector<int> arr(n + 1);
    vector sum(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1];
        cin >> arr[i];
        sum[i][i]++;
    }


}
