#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
int n, m, r;
int result;
int item[102];
vector<pair<int, int>> adj[102];

void init()
{
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }

    for (int i = 0; i < r; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }
}

int dijkstra(int st)
{
    int dist[102];
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작 위치
    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty())
    {
        // 하나 꺼내기
        int cur_vertex = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        // 중복 확인
        if (dist[cur_vertex] != cur_dist)
        {
            continue;
        }

        // 주변 확인
        for (auto nxt : adj[cur_vertex])
        {
            int next_vertex = nxt.second;
            int next_weight = nxt.first;

            // 최단 거리 갱신
            if (dist[next_vertex] > dist[cur_vertex] + next_weight)
            {
                dist[next_vertex] = dist[cur_vertex] + next_weight;
                pq.push({dist[next_vertex], next_vertex});
            }
        }
    }

    int count = 0;

    // 아이템 개수 확인
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] <= m)
        {
            count += item[i];
        }
    }

    return count;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        result = max(result, dijkstra(i));
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
    solve();
    print_result();
    return 0;
}
