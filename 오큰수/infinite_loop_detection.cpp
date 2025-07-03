long long w = 1;
int loop_count = 0;
while (!idx_stack.empty())
{
    if (++loop_count > 1000000) {
        cout << "무한루프 감지!" << endl;
        break;
    }
    const auto top_idx = idx_stack.top();
    max_area = max(max_area, (w++) * height[top_idx]);
    idx_stack.pop();
}
