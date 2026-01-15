#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, M;
long long K;
long long comb_table[201][201];
string result;

void pascal_triangle()
{
    for (int i = 0; i <= 200; i++)
    {
        comb_table[i][0] = 1;
        comb_table[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            comb_table[i][j] = min(K + 1, comb_table[i - 1][j - 1] + comb_table[i - 1][j]);
        }
    }
}

void init()
{
    cin >> N >> M >> K;
    pascal_triangle();

    if (K > comb_table[N + M][N])
    {
        cout << -1 << '\n';
        exit(0);
    }
}

void solve()
{
    int n = N;
    int m = M;

    while (n > 0 || m > 0)
    {
        if (n == 0)
        {
            result += 'z';
            m--;
            continue;
        }
        if (m == 0)
        {
            result += 'a';
            n--;
            continue;
        }

        long long num = comb_table[n + m - 1][n - 1];

        // a 선택
        if (num >= K)
        {
            result += 'a';
            n--;
        }
        // z 선택
        else
        {
            result += 'z';
            K -= num;
            m--;
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
    solve();
    print_result();

    return 0;
}
