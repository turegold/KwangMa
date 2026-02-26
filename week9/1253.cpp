#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long arr[2001];
int result;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        int k = i;
        int start = 0;
        int end = N - 1;

        while (start < end)
        {
            // 자기 자신은 X
            if (k == start)
            {
                start++;
            }
            if (k == end)
            {
                end--;
            }

            // 범위 다시 체크
            if (start >= end)
            {
                break;
            }

            // 찾음
            if (arr[k] == arr[start] + arr[end])
            {
                result++;
                break;
            }

            if (arr[k] > arr[start] + arr[end])
            {
                start++;
            }
            else
            {
                end--;
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
}
