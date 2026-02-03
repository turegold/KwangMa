#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;
int N;
int W[11][11];
int dp[11][1 << 11];

void init()
{
    cin >> N;
    // 비용 입력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }
    // dp 초기화
    for (int i = 0; i < N; i++)
    {
        fill(dp[i], dp[i] + (1 << 11), -1);
    }
}

int TSP(int cur, int visited)
{
    // 순회 완료
    if (visited == ((1 << N) - 1))
    {
        // 도달 불가한 경우
        if (W[cur][0] == 0)
        {
            return INF;
        }
        else
        {
            return W[cur][0];
        }
    }

    // 경로에 대한 비용
    int cost = dp[cur][visited];

    // 이미 계산했으면 반환
    if (cost != -1)
    {
        return cost;
    }

    cost = INF;

    // 주변 도시 방문
    for (int next = 0; next < N; next++)
    {
        // 이미 방문한 경우
        if (visited & (1 << next))
        {
            continue;
        }
        // 길이 없는 경우
        if (W[cur][next] == 0)
        {
            continue;
        }

        // 다음 도시를 재귀적으로 방문
        cost = min(cost, TSP(next, visited | (1 << next)) + W[cur][next]);
    }

    // dp 갱신
    dp[cur][visited] = cost;
    return cost;
}

void print_result(int result)
{
    if (result != INF)
    {
        cout << result << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    init();
    print_result(TSP(0, 1));
    return 0;
}
