// https://www.luogu.com.cn/problem/P1135
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int floor[201];
    int ans[201] = {-1};
    for (int i = 1; i <= n; i++)
    {
        cin >> floor[i];
        ans[i] = -1;
    }
    queue<int> q;
    q.push(a);
    ans[a] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now >= 1 && now <= n)
        {
            int up = now + floor[now];
            int down = now - floor[now];
            if (up <= n && ans[up] == -1)
            {
                ans[up] = ans[now] + 1;
                q.push(up);
            }
            if (down >= 1 && ans[down] == -1)
            {
                ans[down] = ans[now] + 1;
                q.push(down);
            }
        }
    }
    cout << ans[b];

    return 0;
}