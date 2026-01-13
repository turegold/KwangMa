#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N, K;
int coins[101];
int DP[10001];

void init()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> coins[i];
    }
    fill(DP + 1, DP + K + 1, INF);
}

void solve()
{
    for (int i = 1; i <= K; i++)
    {
        // 동전 하나씩 보기
        for (int j = 1; j <= N; j++)
        {
            // 범위 확인
            if (i - coins[j] >= 0)
            {
                DP[i] = min(DP[i], DP[i - coins[j]] + 1);
            }
        }
    }
}

void print_result()
{
    if (DP[K] >= INF || DP[K] < 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << DP[K] << '\n';
    }
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
