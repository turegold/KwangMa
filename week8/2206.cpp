#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[1001][1001];
int result = 1e9;

bool visited[1001][1001][2]; // row, col, wall_break

int d_row[4] = {-1, 0, 1, 0};
int d_col[4] = {0, 1, 0, -1};

void init()
{
    cin >> N >> M;
    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            board[i][j] = temp[j] - '0';
        }
    }
}

void simulate()
{
    // row, col, depth, wall_break
    queue<tuple<int, int, int, int>> Q;

    // 시작점
    Q.push({0, 0, 1, 0});

    while (!Q.empty())
    {
        int cur_row = get<0>(Q.front());
        int cur_col = get<1>(Q.front());
        int depth = get<2>(Q.front());
        int wall_break = get<3>(Q.front());
        Q.pop();

        // 도착
        if (cur_row == N - 1 && cur_col == M - 1)
        {
            if (depth < result)
            {
                result = depth;
                return;
            }
        }

        // 4방향 탐색
        for (int i = 0; i < 4; i++)
        {
            int next_row = cur_row + d_row[i];
            int next_col = cur_col + d_col[i];

            // 조건 확인
            if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M)
            {
                // 다음이 빈 칸
                if (board[next_row][next_col] == 0 && !visited[next_row][next_col][wall_break])
                {
                    visited[next_row][next_col][wall_break] = true;
                    Q.push({next_row, next_col, depth + 1, wall_break});
                }

                // 다음 칸이 벽 + 아직 안 부쉈으면
                else if (board[next_row][next_col] == 1 && wall_break == 0 && !visited[next_row][next_col][1])
                {
                    visited[next_row][next_col][1] = true;
                    Q.push({next_row, next_col, depth + 1, 1});
                }
            }
        }
    }
}

void print_result()
{
    if (result != 1e9)
    {
        cout << result << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    init();
    simulate();
    print_result();
    return 0;
}
