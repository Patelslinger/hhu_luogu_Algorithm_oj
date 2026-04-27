// https://www.luogu.com.cn/problem/P1219
#include <iostream>
using namespace std;

const int maxn = 15;
int ans[maxn];
bool col[maxn];
bool dig1[30]; // 主对角线 左上-右下 row - col (+n补偿正数)
bool dig2[30]; // 副对角线 右上-左下 row + col
int count = 0;
int n;

void dfs(int row)
{
    if (row > n) // row == n+1 表示找到了一种解
    {
        ::count++;
        if (::count < 4)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int c = 1; c <= n; c++)
    {
        // c : 当前处理的所在列
        // col: 列冲突
        // dig1: 主对角线冲突
        // dig2: 副对角线冲突
        if (!col[c] && !dig1[row - c + n] && !dig2[row + c])
        {
            col[c] = true;            // 标记列占用
            dig1[row - c + n] = true; // 标记主对角线占用
            dig2[row + c] = true;     // 标记副对角线占用
            ans[row] = c;             // 记录当前位置

            dfs(row + 1); // 进入下一行

            // 取消占用,回退状态,ans不用回退因为下一次覆盖即可
            col[c] = false;
            dig1[row - c + n] = false;
            dig2[row + c] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ::count << endl;
    return 0;
}