#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[11][11];

int d_row[4] = {-1, 0, 1, 0};
int d_col[4] = {0, 1, 0, -1};
int result = 1e9;

pair<int, int> blue, red;

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            board[i][j] = temp[j];
            if (board[i][j] == 'B')
            {
                blue = {i, j};
            }
            else if (board[i][j] == 'R')
            {
                red = {i, j};
            }
        }
    }
}

tuple<int, int, int, bool> tilt(int row, int col, int i)
{
    int dist = 0;

    // 벽이 아닐 동안 계속 밈
    while (board[row + d_row[i]][col + d_col[i]] != '#')
    {
        row += d_row[i];
        col += d_col[i];
        dist++;

        // 구멍이면?
        if (board[row][col] == 'O')
        {
            return {row, col, dist, true};
        }
    }

    // 구멍 발견 X
    return {row, col, dist, false};
}

void solve()
{
    queue<tuple<int, int, int, int, int>> Q; // {red_row, red_col, blue_row, blue_col, count}
    bool visited[11][11][11][11] = {false};

    // 시작
    Q.push({red.first, red.second, blue.first, blue.second, 0});
    visited[red.first][red.second][blue.first][blue.second] = true;

    while (!Q.empty())
    {
        // 하나 꺼내기
        int cur_red_row = get<0>(Q.front());
        int cur_red_col = get<1>(Q.front());
        int cur_blue_row = get<2>(Q.front());
        int cur_blue_col = get<3>(Q.front());
        int count = get<4>(Q.front());
        Q.pop();

        // 10번 넘으면 패스
        if (count >= 10)
        {
            continue;
        }

        // 4방향으로 기울이기
        for (int i = 0; i < 4; i++)
        {
            tuple<int, int, int, bool> next_red = tilt(cur_red_row, cur_red_col, i);
            tuple<int, int, int, bool> next_blue = tilt(cur_blue_row, cur_blue_col, i);

            int next_red_row = get<0>(next_red);
            int next_red_col = get<1>(next_red);
            int next_red_dist = get<2>(next_red);
            bool is_suc_red = get<3>(next_red);

            int next_blue_row = get<0>(next_blue);
            int next_blue_col = get<1>(next_blue);
            int next_blue_dist = get<2>(next_blue);
            bool is_suc_blue = get<3>(next_blue);

            // 둘 다 구멍에 빠지면
            if (is_suc_red && is_suc_blue)
            {
                continue;
            }

            // 파랑만 성공
            if (!is_suc_red && is_suc_blue)
            {
                continue;
            }

            // 빨강만 성공
            if (is_suc_red && !is_suc_blue)
            {
                result = min(result, count + 1);
                continue;
            }

            // 둘이 같은 위치가 되면
            if (next_red_row == next_blue_row && next_red_col == next_blue_col)
            {
                // 더 많이 이동한 애를 뒤로 물러야 함
                if (next_red_dist > next_blue_dist)
                {
                    next_red_row -= d_row[i];
                    next_red_col -= d_col[i];
                }
                else
                {
                    next_blue_row -= d_row[i];
                    next_blue_col -= d_col[i];
                }
            }

            // 방문 체크
            if (!visited[next_red_row][next_red_col][next_blue_row][next_blue_col])
            {
                visited[next_red_row][next_red_col][next_blue_row][next_blue_col] = true;
                Q.push({next_red_row, next_red_col, next_blue_row, next_blue_col, count + 1});
            }
        }
    }
}

void print_result()
{
    if (result == 1e9)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << result << '\n';
    }
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
