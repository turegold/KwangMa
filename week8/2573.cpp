#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[301][301];
int d_row[4] = {-1, 0, 1, 0};
int d_col[4] = {0, 1, 0, -1};
int result;

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
}

// 빙산이 나뉘어졌는지 확인
bool is_end()
{
    int count = 0;
    bool visited[301][301];
    // visited 초기화
    for (int i = 0; i < N; i++)
    {
        fill(visited[i], visited[i] + M, false);
    }

    // 모든 칸 방문
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // 0이 아니고, 아직 방문하지 않았으면 BFS 진행
            if (board[i][j] != 0 && !visited[i][j])
            {
                count++;
                queue<pair<int, int>> Q;

                Q.push({i, j});
                visited[i][j] = true;

                // 큐가 빌 때 까지
                while (!Q.empty())
                {
                    // 하나 뽑기
                    int cur_row = Q.front().first;
                    int cur_col = Q.front().second;
                    Q.pop();

                    // 주변 탐색
                    for (int d = 0; d < 4; d++)
                    {
                        int next_row = cur_row + d_row[d];
                        int next_col = cur_col + d_col[d];

                        // 조건 확인
                        if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M && !visited[next_row][next_col] && board[next_row][next_col] > 0)
                        {
                            // 방문 처리
                            Q.push({next_row, next_col});
                            visited[next_row][next_col] = true;
                        }
                    }
                }
            }
        }
    }

    if (count == 0)
    {
        cout << 0 << '\n';
        exit(0);
    }
    if (count >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve()
{
    // 빙산이 나뉠 때 까지 반복
    while (!is_end())
    {
        result++;
        int temp[301][301] = {0};
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                // 해당 칸이 빙산인가?
                if (board[i][j] != 0)
                {

                    int cur_height = board[i][j];
                    // 주변 탐색
                    for (int d = 0; d < 4; d++)
                    {
                        int next_row = i + d_row[d];
                        int next_col = j + d_col[d];

                        // 조건 확인
                        if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M)
                        {
                            // 해당 칸이 0이면
                            if (board[next_row][next_col] == 0)
                            {
                                cur_height -= 1;
                            }
                        }
                    }
                    if (cur_height < 0)
                    {
                        cur_height = 0;
                    }
                    temp[i][j] = cur_height;
                }
            }
        }

        // 보드 교체
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                board[i][j] = temp[i][j];
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
    return 0;
}
