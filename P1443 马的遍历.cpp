// https://www.luogu.com.cn/problem/P1443
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, x, y;
vector<vector<int>> graph;
queue<pair<int, int>> q;
int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};

void bfs(int x, int y)
{
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && graph[nx][ny] == -1)
            {

                q.push(make_pair(nx, ny));
                graph[nx][ny] = graph[cx][cy] + 1;
            }
        }
    }
    return;
}
int main()
{
    cin >> n >> m >> x >> y;
    graph.resize(n + 1, vector<int>(m + 1, -1));
    q.push(make_pair(x, y));
    graph[x][y] = 0;
    bfs(x, y);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}