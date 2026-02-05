#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N;
vector<int> arr;
map<int, int> sign; // 0: +, 1: -, 2: *, 3: /
int min_result = 1e9;
int max_result = -1e9;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        sign[i] = num;
    }
}

void check(int cur)
{
    if (cur > max_result)
    {
        max_result = cur;
    }

    if (cur < min_result)
    {
        min_result = cur;
    }
}

int calc(int num, int cur, int s)
{
    // +
    if (s == 0)
    {
        return cur + arr[num];
    }
    // -
    else if (s == 1)
    {
        return cur - arr[num];
    }
    // *
    else if (s == 2)
    {
        return cur * arr[num];
    }
    // /
    else if (s == 3)
    {
        return cur / arr[num];
    }

    return 0;
}

void back_tracking(int num, int cur)
{
    // 종료 조건
    if (num == N)
    {
        check(cur);
        return;
    }

    // 연산자 확인
    for (int i = 0; i < 4; i++)
    {
        if (sign[i] > 0)
        {
            int next_cur = calc(num, cur, i);
            sign[i] -= 1;
            back_tracking(num + 1, next_cur);
            sign[i] += 1;
        }
    }
}

void print_result()
{
    cout << max_result << '\n';
    cout << min_result << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    init();
    back_tracking(1, arr[0]);
    print_result();
    return 0;
}
