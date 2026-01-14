#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long INF = 1e18;
int N, K;
int coins[101];
long long DP[10001];

void init()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    DP[0] = 1;
}

void solve()
{

    // 동전 순회
    for (int i = 0; i < N; i++)
    {
        // 금액 순회
        for (int j = 1; j <= K; j++)
        {
            // 범위
            if (j - coins[i] >= 0)
            {
                DP[j] += DP[j - coins[i]];
            }
        }
    }
}

void print_result()
{
    cout << DP[K] << '\n';
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
