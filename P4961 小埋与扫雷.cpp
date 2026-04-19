// https://www.luogu.com.cn/problem/P4961
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 八个方向的坐标偏移（8连通）
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 存储原始矩阵（1=雷，0=非雷）
    vector<vector<int>> grid(n, vector<int>(m));
    // 标记格子类型：0=雷，1=空格，2=数字
    vector<vector<int>> type(n, vector<int>(m, 0));
    // 标记是否访问过（用于统计空的个数）
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // 输入矩阵
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    // 第一步：预处理每个格子的类型（雷/空格/数字）
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1)
            {
                type[i][j] = 0; // 雷
                continue;
            }

            // 计算周围8格的雷数
            int mine_count = 0;
            for (int k = 0; k < 8; ++k)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                {
                    mine_count++;
                }
            }

            if (mine_count == 0)
            {
                type[i][j] = 1; // 空格（周围无雷）
            }
            else
            {
                type[i][j] = 2; // 数字（周围有雷）
            }
        }
    }

    // 第二步：统计空的个数（空格的8连通块数量）
    int empty_block_count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // 找到未访问的空格，启动BFS遍历连通块
            if (type[i][j] == 1 && !visited[i][j])
            {
                empty_block_count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    // 遍历8个方向
                    for (int k = 0; k < 8; ++k)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && type[nx][ny] == 1 && !visited[nx][ny])
                        {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    // 第三步：统计周围8格无空格的数字个数
    int valid_digit_count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (type[i][j] != 2)
                continue; // 只处理数字格子

            // 检查周围8格是否有空格
            bool has_empty = false;
            for (int k = 0; k < 8; ++k)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && type[nx][ny] == 1)
                {
                    has_empty = true;
                    break;
                }
            }

            if (!has_empty)
            {
                valid_digit_count++;
            }
        }
    }

    // 计算3bv值
    int b3v = empty_block_count + valid_digit_count;
    cout << b3v << endl;

    return 0;
}