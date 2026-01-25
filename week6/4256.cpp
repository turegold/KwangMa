#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int TC;
int N;
int pre_order[1001];
int in_order[1001];
map<int, int> in_pos;

void init()
{
    fill(pre_order, pre_order + 1001, 0);
    fill(in_order, in_order + 1001, 0);
    in_pos.clear();
}

void solve(int pre_L, int pre_R, int in_L, int in_R)
{

    if (pre_L > pre_R || in_L > in_R)
    {
        return;
    }

    // pre_order에서의 root
    int root = pre_order[pre_L];
    // in_order에서의 root의 위치
    int root_pos = in_pos[root];

    // 왼쪽 가지 사이즈
    int left_size = root_pos - in_L;

    // 왼쪽 가지
    solve(pre_L + 1, pre_L + left_size, in_L, root_pos - 1);
    // 오른쪽 가지
    solve(pre_L + left_size + 1, pre_R, root_pos + 1, in_R);
    cout << root << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        cin >> N;
        init();

        // 전위 순회 입력
        for (int i = 0; i < N; i++)
        {
            cin >> pre_order[i];
        }

        // 중위 순회 입력
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;

            in_order[i] = temp;
            in_pos[temp] = i;
        }

        solve(0, N - 1, 0, N - 1);
        cout << '\n';
    }

    return 0;
}
