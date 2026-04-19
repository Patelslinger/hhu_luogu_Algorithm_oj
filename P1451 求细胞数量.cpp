// https://www.luogu.com.cn/problem/P1451
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 105;
char grid[MAX][MAX]; // 存储矩阵
bool vis[MAX][MAX];  // 访问标记
int n, m;

// 上下左右四个方向
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// BFS 遍历整个连通块
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true; // 入队就标记，避免重复入队

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        int cx = now.first;
        int cy = now.second;

        // 遍历四个方向
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            // 合法：不越界、未访问、是细胞
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] != '0')
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 找到新细胞
            if (grid[i][j] != '0' && !vis[i][j])
            {
                ans++;
                bfs(i, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}