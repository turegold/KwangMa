#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> childs[51];
int start, tar, result;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        if (p >= 0)
        {
            childs[p].push_back(i);
        }
        else
        {
            start = i;
        }
    }
    cin >> tar;
    if (tar == start)
    {
        cout << 0 << '\n';
        exit(0);
    }
}

void solve(int cur)
{
    // cout << "현재 노드: " << cur << '\n';
    // 자식이 없으면 재귀 종료
    if (childs[cur].empty())
    {
        result++;
        return;
    }

    // 자식이 하나였는데, 그게 tar였다면 재귀 종료
    if (childs[cur].size() == 1 && childs[cur][0] == tar)
    {
        result++;
        return;
    }

    // 자식들 둘러보기
    for (auto x : childs[cur])
    {
        // tar면 무시
        if (x == tar)
        {
            continue;
        }

        solve(x);
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
    solve(start);
    print_result();
    return 0;
}
