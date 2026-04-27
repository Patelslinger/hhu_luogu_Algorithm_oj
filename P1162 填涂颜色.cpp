// https://www.luogu.com.cn/problem/P1162
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<int>> type(n, vector<int>(n, -1)); //-1是外面，0是边框，1是内层
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<pair<int, int>> temp;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                type[i][j] = 0;
            }
        }
    }

    bool is_inner = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            is_inner = true;
            if (map[i][j] == 1)
            {
                continue;
            }
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                type[i][j] = 0;
                is_inner = false;
            }
            if (!vis[i][j])
            {
                q.push(make_pair(i, j));
                vis[i][j] = true;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    temp.push_back(make_pair(x, y));
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 0 && !vis[nx][ny])
                        {
                            q.push(make_pair(nx, ny));
                            vis[nx][ny] = true;
                            if (nx == 0 || nx == n - 1 || ny == 0 || ny == n - 1)
                            {
                                is_inner = false;
                            }
                        }
                    }
                }
                if (is_inner)
                {
                    for (auto p : temp)
                    {
                        map[p.first][p.second] = 2;
                    }
                    type[i][j] = 1;
                }
                temp.clear();
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}