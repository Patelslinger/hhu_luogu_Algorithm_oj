// https://www.luogu.com.cn/problem/P5318
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    int id;
    vector<int> child_index;
    bool visited;
};

void dfs(int index, vector<node> &nodes)
{
    if (nodes[index].visited)
    {
        return;
    }
    else
    {
        cout << nodes[index].id << " ";

        nodes[index].visited = true;
    }
    for (int i : nodes[index].child_index)
    {
        if (!nodes[i].visited)
        {
            dfs(i, nodes);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> nodes(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[x].child_index.push_back(y);
    }

    for (int i = 0; i <= n; i++)
    {
        nodes[i].id = i;
        nodes[i].visited = false;
        sort(nodes[i].child_index.begin(), nodes[i].child_index.end());
    }

    // DFS
    dfs(1, nodes);
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        nodes[i].visited = false;
    }

    // BFS
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        if (!nodes[index].visited)
        {
            cout << nodes[index].id << " ";
            nodes[index].visited = true;
            for (int i : nodes[index].child_index)
            {
                q.push(i);
            }
        }
    }

    return 0;
}