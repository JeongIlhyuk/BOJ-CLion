// Problem: 개똥벌레
// URL: https://www.acmicpc.net/problem/3020
// Time Limit: 1000 ms
// Memory Limit: 128 MB

/*
문제:
개똥벌레 한 마리가 장애물(석순과 종유석)로 가득찬 동굴에 들어갔다. 동굴의 길이는 N미터이고, 높이는 H미터이다. (N은 짝수) 첫 번째 장애물은 항상 석순이고, 그 다음에는 종유석과 석순이 번갈아가면서 등장한다.아래 그림은 길이가 14미터이고 높이가 5미터인 동굴이다. (예제 그림)이 개똥벌레는 장애물을 피하지 않는다. 자신이 지나갈 구간을 정한 다음 일직선으로 지나가면서 만나는 모든 장애물을 파괴한다.위의 그림에서 4번째 구간으로 개똥벌레가 날아간다면 파괴해야하는 장애물의 수는 총 여덟개이다. (4번째 구간은 길이가 3인 석순과 길이가 4인 석순의 중간지점을 말한다)하지만, 첫 번째 구간이나 다섯 번째 구간으로 날아간다면 개똥벌레는 장애물 일곱개만 파괴하면 된다.동굴의 크기와 높이, 모든 장애물의 크기가 주어진다. 이때, 개똥벌레가 파괴해야하는 장애물의 최솟값과 그러한 구간이 총 몇 개 있는지 구하는 프로그램을 작성하시오.

입력:
첫째 줄에 N과 H가 주어진다. N은 항상 짝수이다. (2 ≤ N ≤ 200,000, 2 ≤ H ≤ 500,000)다음 N개 줄에는 장애물의 크기가 순서대로 주어진다. 장애물의 크기는 H보다 작은 양수이다.

출력:
첫째 줄에 개똥벌레가 파괴해야 하는 장애물의 최솟값과 그러한 구간의 수를 공백으로 구분하여 출력한다.

알고리즘 분류:
이분 탐색, 누적 합, 차분 배열 트릭
*/

#include <iostream>
#include <vector>
#include <bit>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;
    vector<int> floor(h + 1);
    vector<int> ceiling(h + 1);

    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        if (i % 2 == 0)
        {
            floor[input]++;
        }
        else
        {
            ceiling[h - input + 1]++;
        }
    }

    // // 누적합 계산 후에 이걸 추가해봐
    // cout << "floor array: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << floor[i] << " ";
    // }
    // cout << endl;
    //
    // cout << "ceiling array: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << ceiling[i] << " ";
    // }
    // cout << endl;
    //
    // // 각 구간별 장애물 개수도 출력
    // cout << "obstacles per section: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << ceiling[i] + floor[i] << " ";
    // }
    // cout << endl;

    for (int i = 2; i <= h; ++i)
    {
        ceiling[i] += ceiling[i - 1];
        floor[h - i + 1] += floor[h - i + 2];
    }

    // // 누적합 계산 후에 이걸 추가해봐
    // cout << "floor array: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << floor[i] << " ";
    // }
    // cout << endl;
    //
    // cout << "ceiling array: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << ceiling[i] << " ";
    // }
    // cout << endl;
    //
    // // 각 구간별 장애물 개수도 출력
    // cout << "obstacles per section: ";
    // for (int i = 1; i <= h; i++)
    // {
    //     cout << ceiling[i] + floor[i] << " ";
    // }
    // cout << endl;

    int result = 200000;
    int cnt = 1;
    for (int i = 1; i <= h; ++i)
    {
        if (ceiling[i] + floor[i] < result)
        {
            result = ceiling[i] + floor[i];
            cnt = 1;
            continue;
        }
        if (ceiling[i] + floor[i] == result)cnt++;
    }

    cout << result << " " << cnt;
}