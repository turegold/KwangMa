#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 북, 동, 남, 서
int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

int main()
{
    int N;
    int const INF = 1e9;
    int TC = 1;

    while (true)
    {
        int dist[130][130]; // 각 칸의 최소 비용
        int board[130][130];
        cin >> N;

        if (N == 0)
        {
            break;
        }

        // 입력부
        for (int i = 0; i < N; i++)
        {
            // 거리 INF로 채우기
            fill(dist[i], dist[i] + N, INF);
            for (int j = 0; j < N; j++)
            {
                cin >> board[i][j];
            }
        }

        // {거리, {행, 열}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // 시작 지점
        dist[0][0] = board[0][0];
        pq.push({dist[0][0], {0, 0}});

        while (!pq.empty())
        {
            // 하나 꺼내기
            int cur_dist = pq.top().first;
            int cur_row = pq.top().second.first;
            int cur_col = pq.top().second.second;
            pq.pop();

            // 중복 확인
            if (dist[cur_row][cur_col] != cur_dist)
            {
                continue;
            }

            // 4방향 확인
            for (int i = 0; i < 4; i++)
            {
                int next_row = cur_row + drow[i];
                int next_col = cur_col + dcol[i];

                // 유효성 확인
                if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N)
                {
                    // 최단 비용 체크
                    if (dist[next_row][next_col] > dist[cur_row][cur_col] + board[next_row][next_col])
                    {
                        dist[next_row][next_col] = dist[cur_row][cur_col] + board[next_row][next_col];
                        pq.push({dist[next_row][next_col], {next_row, next_col}});
                    }
                }
            }
        }

        // 출력부
        cout << "Problem " << TC << ": " << dist[N - 1][N - 1] << '\n';
        TC++;
    }
}
