#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> adj[200001];
int colors[200001];
int result;

void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> colors[i];
    }

    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void solve(int num, int parent, int cur_color)
{
    // 현재 목표랑 색이 다르면 칠해야 함
    if (colors[num] != cur_color)
    {
        result++;
        cur_color = colors[num];
    }

    // 자식으로 이동
    for (auto nxt : adj[num])
    {
        // 부모로는 이동 불가
        if (nxt != parent)
        {
            solve(nxt, num, cur_color);
        }
    }
}

void print_result()
{
    cout << result << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    init();
    solve(1, -1, 0);
    print_result();

    return 0;
}
