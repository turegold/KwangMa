#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> pre_order;
int num;
void init()
{
    int temp;
    while (cin >> temp)
    {
        pre_order.push_back(temp);
        num++;
    }
}

int find_idx(int left, int right)
{
    int tar = left + 1;
    while (tar <= right)
    {
        // root보다 큰 첫 값이 나오면 종료
        if (pre_order[left] < pre_order[tar])
        {
            break;
        }
        tar++;
    }
    return tar;
}

void solve(int left, int right)
{
    if (left > right)
    {
        return;
    }

    // root 보다 큰 첫 값 찾기
    int k = find_idx(left, right);

    // 왼쪽
    solve(left + 1, k - 1);
    // 오른쪽
    solve(k, right);
    // 현재
    cout << pre_order[left] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    init();
    solve(0, num - 1);

    return 0;
}
