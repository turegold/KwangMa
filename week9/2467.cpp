#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<long long> arr;

long long left_result, right_result;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve()
{
    // 투포인터
    int start = 0;
    int end = N - 1;

    left_result = arr[start];
    right_result = arr[end];

    while (start < end)
    {

        long long cur = arr[start] + arr[end];
        long long result_hap = left_result + right_result;

        // 결과 갱신
        if (abs(cur) < abs(result_hap))
        {
            left_result = arr[start];
            right_result = arr[end];
        }
        // 음수면 start를 오른쪽으로
        if (cur < 0)
        {
            start++;
        }
        else if (cur > 0)
        {
            end--;
        }
        // 0이면 걍 종료
        else
        {
            return;
        }
    }
}

void print_result()
{
    cout << left_result << ' ' << right_result << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    init();
    solve();
    print_result();
}
