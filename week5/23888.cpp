#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long a, d, q;

void init()
{
    cin >> a >> d;
    cin >> q;
}

long long calc_hap(long long l, long long r)
{

    long long Sum_r = r * (2 * a + (r - 1) * d) / 2;
    long long Sum_l = (l - 1) * (2 * a + (l - 2) * d) / 2;
    return Sum_r - Sum_l;
}

long long calc_gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve()
{
    for (long long i = 0; i < q; i++)
    {
        long long query, l, r;
        cin >> query >> l >> r;

        if (query == 1)
        {
            long long sum = calc_hap(l, r);
            cout << sum << '\n';
        }
        else if (query == 2)
        {
            long long first = a + (l - 1) * d;
            if (l == r)
            {
                cout << first << '\n';
            }
            else
            {
                long long gcd = calc_gcd(first, d);
                cout << gcd << '\n';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    init();
    solve();

    return 0;
}
