// https://www.luogu.com.cn/problem/P1379
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

string ed = "123804765";
int dx[4] = {-3, 3, -1, 1};
// 上: -3 行减一
// 下: 3 行加一
// 左: -1 列减一
// 右: 1 列加一

int main()
{
    string start;
    cin >> start;
    queue<pair<string, int>> q; // value: state, step
    unordered_set<string> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        string state = now.first;
        int step = now.second;

        if (state == ed)
        {
            cout << step << endl;
            return 0;
        }

        int pos = state.find('0');
        for (int i = 0; i < 4; i++)
        {
            int next = pos + dx[i];
            if (next < 0 || next >= 9) // 超出边界
            {
                continue;
            }
            if (pos % 3 == 0 && i == 2) // 第一列,不能左移
            {
                continue;
            }
            if (pos % 3 == 2 && i == 3) // 第三列,不能右移
            {
                continue;
            }

            swap(state[pos], state[next]);

            if (!visited.count(state))
            {
                visited.insert(state);
                q.push({state, step + 1});
            }
            swap(state[pos], state[next]);
        }
    }

    return 0;
}