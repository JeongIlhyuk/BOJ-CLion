#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pair<int, int>> events;
    
    for (int i = 0; i < n; ++i)
    {
        int s, e;
        cin >> s >> e;
        events.push_back({s, 1});  // 시작점
        events.push_back({e, -1}); // 끝점
    }
    
    sort(events.begin(), events.end());
    
    int current = 0, max_overlap = 0;
    
    for (auto [pos, type] : events)
    {
        current += type;
        max_overlap = max(max_overlap, current);
    }
    
    cout << max_overlap << endl;
    
    return 0;
}