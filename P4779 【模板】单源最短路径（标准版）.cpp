#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 邻接表存储边：first是终点，second是边权
typedef pair<int, long long> PII;
const int MAXN = 1e5 + 5;

vector<PII> edge[MAXN]; // 邻接表
long long dist[MAXN];   // 存储最短距离，用long long防止溢出
bool vis[MAXN];         // 标记是否已确定最短距离
int n, m, s;

// 堆优化Dijkstra
void dijkstra(int start)
{
    // 初始化：距离无穷大，起点为0
    fill(dist, dist + n + 1, LLONG_MAX);
    fill(vis, vis + n + 1, false);
    dist[start] = 0;

    // 小根堆：pair(当前距离, 节点编号)，优先弹出距离最小的
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});

    while (!q.empty())
    {
        // 取出堆顶节点
        auto [d, u] = q.top();
        q.pop();

        // 已确定最短距离，跳过
        if (vis[u])
            continue;
        vis[u] = true;

        // 遍历所有邻边
        for (auto [v, w] : edge[u])
        {
            // 松弛操作：如果能更短就更新
            if (!vis[v] && dist[v] > d + w)
            {
                dist[v] = d + w;
                q.push({dist[v], v});
            }
        }
    }
}

int main()
{
    // 加速输入输出，大数据必备
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;
    // 建图
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edge[u].emplace_back(v, w);
    }

    // 计算最短路
    dijkstra(s);

    // 输出结果
    for (int i = 1; i <= n; ++i)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}