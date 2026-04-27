// https://www.luogu.com.cn/problem/P1996
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int count = 0;
    while (q.size() > 0)
    {
        count++;
        int temp = q.front();
        q.pop();
        if (count != m)
        {
            q.push(temp);
        }
        else
        {
            cout << temp << " ";
            count = 0;
        }
    }
    return 0;
}