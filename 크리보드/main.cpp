// Problem: 크리보드
// URL: https://www.acmicpc.net/problem/11058
// Time Limit: 1000 ms
// Memory Limit: 256 MB

/*
문제:
크리보드는 kriii가 만든 신기한 키보드이다. 크리보드에는 버튼이 4개만 있으며, 하는 역할은 다음과 같다.화면에 A를 출력한다.Ctrl-A: 화면을 전체 선택한다Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.크리보드의 버튼을 총 N번 눌러서 화면에 출력된 A개수를 최대로하는 프로그램을 작성하시오.

입력:
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력:
크리보드의 버튼을 총 N번 눌러서 화면에 출력할 수 있는 A 개수의 최댓값을 출력한다.

알고리즘 분류:
다이나믹 프로그래밍
*/

#include <iostream>
#include <vector>
#include <bit>

#define SELECT 2
#define COPY 0
#define PASTE 1

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n < 7)
    {
        cout << n;
        return 0;
    }
    vector<int> dp(n + 1);
    vector<int> buffer(n + 1);
    dp[4] = 3;
    dp[5] = 3;
    buffer[5] = 3;
    buffer[6] = 3;
    dp[6] = 6;
    for (int i = 7; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        buffer[i] = buffer[i - 1];
        if (n - i > 0 && buffer[i - 1] * 3 <= dp[i - 1])
        {
            //복사 조건
            buffer[i] = dp[i];
            continue;
        }
        if (n == i || buffer[i] * 3 > dp[i - 2]) //붙여넣기 조건
        {
            dp[i] += buffer[i - 1];
        }
        //그 외 전체 선택 조건
    }
    cout << dp[n] << '\n';

    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << i << ":" << dp[i] << " ";
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << i << ":" << buffer[i] << " ";
    // }
}
