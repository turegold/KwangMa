#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int size_D, size_M;
long long D[51], M[51];
long long result;

void init()
{
    cin >> size_D >> size_M;
    for (int i = 0; i < size_D; i++)
    {
        cin >> D[i];
    }
    for (int i = 0; i < size_M; i++)
    {
        cin >> M[i];
    }
}

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    long long Lcm = D[0];
    // 배열 D의 Lcm 구하기
    if (size_D > 1)
    {
        for (int i = 1; i < size_D; i++)
        {
            Lcm = lcm(Lcm, D[i]);
        }
    }

    long long Gcd = M[0];
    // 배열 M의 Gcd 구하기
    if (size_M > 1)
    {
        for (int i = 1; i < size_M; i++)
        {
            Gcd = gcd(Gcd, M[i]);
        }
    }

    // Lcm이 Gcd를 나누지 못하면 불가능
    if (Gcd % Lcm != 0)
    {
        result = 0;
        return;
    }

    long long target = Gcd / Lcm;

    // Gcd / Lcm의 약수의 개수 구하기
    for (long long i = 1; i * i <= target; i++)
    {
        if (target % i == 0)
        {
            result++;
            if (i * i < target)
            {
                result++;
            }
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
