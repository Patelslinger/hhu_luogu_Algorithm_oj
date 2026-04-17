// https://www.luogu.com.cn/problem/P1002
#include <iostream>
#define ll long long
using namespace std;
ll map[21][21] = {0};
int dx[9] = {-2, -2, -1, -1, 1, 1, 2, 2, 0};
int dy[9] = {-1, 1, -2, 2, -2, 2, -1, 1, 0};

int main()
{
    int endx, endy, hx, hy;
    cin >> endx >> endy >> hx >> hy;

    for (int i = 0; i < 9; i++)
    {
        int x = hx + dx[i];
        int y = hy + dy[i];
        if (0 <= x && x <= endx && 0 <= y && y <= endy)
        {
            map[x][y] = -1;
        }
        else
        {
            continue;
        }
    }
    map[0][0] = 1;
    for (int i = 1; i <= endx; i++)
    {
        if (map[i][0] != -1)
        {
            map[i][0] = map[i - 1][0];
        }
    }
    for (int j = 1; j <= endy; j++)
    {
        if (map[0][j] != -1)
        {
            map[0][j] = map[0][j - 1];
        }
    }

    for (int i = 1; i <= endx; i++)
    {
        for (int j = 1; j <= endy; j++)
        {
            // 如果当前不是
            if (map[i][j] != -1)
            {
                // 如果左边是障碍
                if (map[i][j - 1] == -1)
                {
                    // 当前的只能从上面下来
                    map[i][j] = map[i - 1][j];
                }
                // 如果上面是障碍
                else if (map[i - 1][j] == -1)
                {
                    // 当前的只能从左边过来
                    map[i][j] = map[i][j - 1];
                }
                else
                {
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
                }
            }
        }
    }
    cout << map[endx][endy];

    return 0;
}