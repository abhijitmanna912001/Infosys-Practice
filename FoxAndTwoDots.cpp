#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> board;
vector<vector<bool>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(int x, int y, int from_x, int from_y, char color)
{
    visited[x][y] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (board[nx][ny] != color)
                continue;

            if (!visited[nx][ny])
            {
                if (dfs(nx, ny, x, y, color))
                    return true;
            }
            else
            {
                if (!(nx == from_x && ny == from_y))
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    board.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                if (dfs(i, j, -1, -1, board[i][j]))
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}