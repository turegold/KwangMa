#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
int result;
vector<int> arr;
void init()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

bool is_possible(int mid)
{
    int count = 1;
    int prev = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        // 공유기를 설치할 수 있나?
        if (arr[i] - prev >= mid)
        {
            count++;
            prev = arr[i];
        }

        // 공유기를 모두 설치했나?
        if (count >= C)
        {
            return true;
        }
    }

    // 모든 공유기 설치 실패
    return false;
}

void solve()
{
    int left = 1;
    int right = arr[N - 1] - arr[0];
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (is_possible(mid))
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
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
