// Problem: 트리 순회
// URL: https://www.acmicpc.net/problem/1991
// Time Limit: 2000 ms
// Memory Limit: 128 MB

/*
문제:
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.예를 들어 위와 같은 이진 트리가 입력되면,전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)가 된다.

입력:
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

출력:
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

알고리즘 분류:
트리, 재귀
*/

#include <iostream>
#include <vector>
#include <bit>
#include <climits>


using namespace std;

vector<pair<char, char>> arr;

void preorder(const char node)
{
    if (node == '.')
    {
        return;
    }
    cout << node;
    preorder(arr[node].first);
    preorder(arr[node].second);
}

void inorder(const char node)
{
    if (node == '.')
    {
        return;
    }
    inorder(arr[node].first);
    cout << node;
    inorder(arr[node].second);
}

void postorder(const char node)
{
    if (node == '.')
    {
        return;
    }
    postorder(arr[node].first);
    postorder(arr[node].second);
    cout << node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    arr.resize(n + 'A');
    while (n--)
    {
        char node, c1, c2;
        cin >> node >> c1 >> c2;
        arr[node].first = c1;
        arr[node].second = c2;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
}
