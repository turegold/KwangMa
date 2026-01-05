#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
int N, D;
int DP[10001];
vector<pair<int, int>> shortcuts[10001];

void init()
{
    cin >> N >> D;
    for (int i = 0; i < N; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        shortcuts[u].push_back({v, cost});
    }
    fill(DP + 1, DP + D + 1, INF);
}

void solve()
{
    for (int i = 0; i < D; i++)
    {
        for (auto sc : shortcuts[i])
        {
            int next_vertex = sc.first;
            int next_cost = sc.second;

            // 1. 지름길을 쓴다
            DP[next_vertex] = min(DP[next_vertex], DP[i] + next_cost);
        }
        // 2. 지름길을 안쓴다.
        DP[i + 1] = min(DP[i + 1], DP[i] + 1);
    }
}

void print_result()
{
    cout << DP[D] << '\n';
}

int main()
{
    init();
    solve();
    print_result();
    return 0;
}
