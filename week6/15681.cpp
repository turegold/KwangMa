#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, R, Q;

vector<int> tree[100001];
int parent[100001];
int subtree[100001];

void input()
{
    cin >> N >> R >> Q;
    int u, v;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

int dfs(int cur)
{
    for (int child : tree[cur])
    {
        // 부모일 경우 패스
        if (child == parent[cur])
        {
            continue;
        }
        parent[child] = cur;
        subtree[cur] += dfs(child);
    }
    return ++subtree[cur];
}

void solve()
{
    parent[R] = 0; // 루트의 부모는 존재 X
    dfs(R);
    int tar;
    for (int i = 0; i < Q; i++)
    {
        cin >> tar;
        cout << subtree[tar] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
    return 0;
}
