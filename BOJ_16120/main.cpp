// Problem: PPAP
// URL: https://www.acmicpc.net/problem/16120
// Time Limit: 1000
// Memory Limit: 512

/*
문제:
bryan은 PPAP를 좋아한다. bryan은 어떻게 하면 사람들에게 PPAP를 전파할 수 있을까 고민하던 중PPAP 문자열이라는 것을 고안하게 되었다.PPAP 문자열은 문자열P에서 시작하여, 문자열 내의P를PPAP로 바꾸는 과정을 반복하여 만들 수 있는 문자열로 정의된다. 정확하게는 다음과 같이 정의된다.P는 PPAP 문자열이다.PPAP 문자열에서P하나를PPAP로 바꾼 문자열은 PPAP 문자열이다.예를 들어PPAP는 PPAP 문자열이다. 또한,PPAP의 두 번째P를PPAP로 바꾼PPPAPAP역시 PPAP 문자열이다.문자열이 주어졌을 때, 이 문자열이 PPAP 문자열인지 아닌지를 알려주는 프로그램을 작성하여라.

입력:
첫 번째 줄에 문자열이 주어진다. 문자열은 대문자 알파벳P와A로만 이루어져 있으며, 문자열의 길이는 1 이상 1,000,000 이하이다.

출력:
첫 번째 줄에 주어진 문자열이 PPAP 문자열이면PPAP를, 아닌 경우NP를 출력한다.

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

    string str;
    cin >> str;

    vector<char> stk;
    for (const char ch : str)
    {
        if (!stk.empty() && stk.back() == 'A')
        {
            if (stk.size() < 3 || ch == 'A')
            {
                cout << "NP";
                return 0;
            }
            stk.pop_back();
            stk.pop_back();
            continue;
        }
        stk.push_back(ch);
    }
    cout << ((stk.size() != 1) || stk.back() == 'A' ? "NP" : "PPAP");
}
