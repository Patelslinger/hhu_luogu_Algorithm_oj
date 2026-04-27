// https://www.luogu.com.cn/problem/B3625
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                map[i][j] = 1;
            }
            else if (c = '.')
            {
                map[i][j] = 0;
            }
        }
    }
    bool can_reach_end = false;
    q.push({0, 0});
    vis[0][0] = true;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        if (x == n - 1 && y == m - 1)
        {
            can_reach_end = true;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && map[nx][ny] == 0)
            {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    if (can_reach_end)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}