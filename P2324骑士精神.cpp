// https://www.luogu.com.cn/problem/P2324
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int target[5][5] = {
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1},
    {0, 0, 2, 1, 1}, // 2 代表空位 '*'
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}};

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int board[5][5];
int max_depth;
bool success;

// 计算当前状态与目标的差距（估价函数）
int get_h()
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] != target[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs(int step, int x, int y, int last_x, int last_y)
{
    int h = get_h();
    if (h == 0)
    {
        success = true;
        return;
    }
    // 核心剪枝：当前步数 + 理论最小剩余步数 > 限制步数
    if (step + h - 1 > max_depth)
        return;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
        if (nx == last_x && ny == last_y)
            continue; // 避免跳回上一步，简单去重

        swap(board[x][y], board[nx][ny]);
        dfs(step + 1, nx, ny, x, y);
        swap(board[x][y], board[nx][ny]); // 回溯

        if (success)
            return;
    }
}

void solve()
{
    int start_x, start_y;
    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++)
        {
            if (s[j] == '*')
            {
                board[i][j] = 2;
                start_x = i;
                start_y = j;
            }
            else
            {
                board[i][j] = s[j] - '0';
            }
        }
    }

    success = false;
    // 迭代加深：从小到大限制搜索深度
    for (max_depth = 0; max_depth <= 15; max_depth++)
    {
        dfs(0, start_x, start_y, -1, -1);
        if (success)
        {
            cout << max_depth << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}