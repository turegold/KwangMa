#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long A, B;
bool is_prime[10000001];
long long limit;
int result;

// 에라토스테네스의 체로 합성수 체크
void elatos()
{
    limit = (int)sqrt(B);
    fill(is_prime, is_prime + limit + 1, true);
    is_prime[1] = false;
    for (long long i = 2; i <= limit; i++)
    {
        // 이미 합성수면 넘어감
        if (!is_prime[i])
        {
            continue;
        }
        for (long long j = 2; i * j <= limit; j++)
        {
            is_prime[i * j] = false;
        }
    }
}

void init()
{
    cin >> A >> B;
    elatos();
}

void solve()
{
    for (long long i = 2; i <= limit; i++)
    {
        if (!is_prime[i])
        {
            continue;
        }
        long long num = i * i;
        while (num <= B)
        {

            if (num >= A)
            {
                result++;
            }

            if (num > B / i)
            {
                break;
            }
            num *= i;
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
}
