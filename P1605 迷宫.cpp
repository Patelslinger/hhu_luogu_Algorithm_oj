// https://www.luogu.com.cn/problem/P1605
#include <iostream>
#include <vector>

using namespace std;
int sx, sy, fx, fy;
int n, m, t;
int count = 0;
int map[8][8] = {0};
bool visited[8][8] = {false};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && map[nx][ny] == 0)
        {
            if (nx == fx && ny == fy)
            {
                ::count++;
                return;
            }
            else
            {
                visited[nx][ny] = true;
                dfs(nx, ny);
                visited[nx][ny] = false;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> t;

    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    visited[sx][sy] = true;
    dfs(sx, sy);
    cout << ::count << endl;
    return 0;
}
