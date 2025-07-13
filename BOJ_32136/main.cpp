#include <bits/stdc++.h>
using namespace std;

bool canSolve(vector<int>& a, long long T) {
    int n = a.size();

    for (int i = 1; i <= n; i++) {  // 모든 가능한 히터 위치 체크
        bool possible = true;
        for (int j = 0; j < n; j++) {
            long long dist = abs(i - (j + 1));
            if (dist * a[j] > T) {
                possible = false;
                break;
            }
        }
        if (possible) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long left = 0, right = 0;

    // 상한: 최악의 경우
    for (int i = 0; i < n; i++) {
        right = max(right, (long long)a[i] * (n - 1));
    }

    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canSolve(a, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}