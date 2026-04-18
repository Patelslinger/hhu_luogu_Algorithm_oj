// https://www.luogu.com.cn/problem/P1219
#include <iostream>
using namespace std;

const int maxn = 15;
int ans[maxn];
bool col[maxn];
bool dig1[30]; // 主对角线 左上-右下
bool dig2[30]; // 副对角线 右上-左下
int count = 0;
int n;

void dfs(int row)
{
    if (row > n)
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
        if (!col[c] && !dig1[row - c + n] && !dig2[row + c])
        {
            col[c] = true;
            dig1[row - c + n] = true;
            dig2[row + c] = true;
            ans[row] = c;

            dfs(row + 1);

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