#include <iostream>
#include <vector>
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