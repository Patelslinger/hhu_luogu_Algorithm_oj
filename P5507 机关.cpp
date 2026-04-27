// https://www.luogu.com.cn/problem/P5507
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef int State;

struct Node
{
    int g, h, s;
    bool operator>(const Node &other) const
    {
        return (g + h) > (other.g + other.h);
    }
};

int start_state[13];
int links[13][5];            // 联动规则 links[旋钮][状态] = 联动旋钮
int dist[1 << 24];           // 记录到每个状态的最小步数
pair<int, int> pre[1 << 24]; // pre[新状态] = {操作旋钮, 旧状态}

// 启发函数：计算预估代价（可采纳，保证最优解）
inline int get_h(State s)
{
    int res = 0;
    for (int i = 0; i < 12; i++)
    {
        int cur = (s >> (i * 2)) & 3; // s >> (i * 2): 第i个旋钮的2位移到最右边 , &3: 3的二进制为11, 取出这两位得到当前状态（0~3）
        res += (4 - cur) % 4;         // 每个旋钮归1需要的次数
    }
    return (res + 1) >> 1; // 一次操作旋转2个，向上取整
}

// 旋转旋钮 i，返回新状态（你原版逻辑完全保留）
inline State rotate(State s, int i)
{
    int pos = i - 1;
    int cur_v = ((s >> (pos * 2)) & 3) + 1; //+1还原1~4的状态
    int target = links[i][cur_v] - 1;

    // 旋转自己
    int next_v = cur_v % 4;
    s = (s & ~(3 << (pos * 2))) | (next_v << (pos * 2));
    // 3 << (pos * 2): 生成11,并移动到对应位置
    // ~ : 按位取反,对应位置变为00,其他位置全1
    // s & : 按位与,对应位置为00,其他位置为原值
    // next_v << (pos * 2) : 把新状态next_v左移到对应位置
    // | : 按位或,对应位置为新值,其他位置为原值

    // 旋转联动旋钮
    int tar_v = (s >> (target * 2)) & 3;
    int next_tar_v = (tar_v + 1) % 4;
    s = (s & ~(3 << (target * 2))) | (next_tar_v << (target * 2));

    return s;
}

int main()
{
    memset(dist, 0x3f, sizeof(dist));
    State start = 0;

    // 输入读取
    for (int i = 1; i <= 12; i++)
    {
        int s;
        scanf("%d", &s);
        start |= ((s - 1) << ((i - 1) * 2));
        // s-1: 输入1~4，转化为0~3
        // << ((i - 1) * 2): 左移i*2位，对应第i个旋钮的2位
        // | : 按位或,对应位置为新值,其他位置为原值

        for (int j = 1; j <= 4; j++)
        {
            scanf("%d", &links[i][j]);
        }
    }

    // A* 优先队列
    priority_queue<Node, vector<Node>, greater<Node>> pq; // 优先队列(小顶堆)，按f值排序 ,参数为(元素类型,容器类型,比较函数)
    int h0 = get_h(start);
    dist[start] = 0;
    pq.push({0, h0, start});

    while (!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();

        // 到达目标：全0（所有旋钮都是状态1）
        if (cur.s == 0)
        {
            printf("%d\n", cur.g);

            // 回溯路径
            vector<int> path;
            State temp = cur.s;
            while (temp != start) // 回溯到起点
            {
                path.push_back(pre[temp].first); // 操作的旋钮入容器
                temp = pre[temp].second;         // 滚动为上一个状态 , 继续往前找
                /* 操作真实顺序：1 → 2 → 3
                状态流转：S_start->​​ S1​ -> ​S2 -> ​S_end​
                    pre[S_end] = {3, S2}
                    pre[S2] = {2, S1}
                    pre[S1] = {1, S_start}

                回溯存入：先存 3 → 再存 2 → 再存 1此时 path = [ 3, 2, 1 ] */
            }

            // 逆序输出
            for (int i = path.size() - 1; i >= 0; i--)
            {
                printf("%d", path[i]);
                if (i != 0)
                    printf(" ");
            }
            printf("\n");
            return 0;
        }

        // 不是最优路径，跳过
        if (cur.g > dist[cur.s])
            continue;

        // 枚举旋转 1~12 号旋钮
        for (int i = 1; i <= 12; i++)
        {
            State next_s = rotate(cur.s, i); // 旋转第i号旋钮,得到新状态
            if (dist[next_s] > cur.g + 1)    // 如果预设中到达新状态的最小步数大于当前步数+1
            {
                dist[next_s] = cur.g + 1; // 更新到达新状态的最小步数
                pre[next_s] = {i, cur.s}; // 更新前驱状态
                // 加入优先队列
                pq.push({cur.g + 1, get_h(next_s), next_s});
                /* pq.push(
                    {
                        cur.g + 1,     // 新节点的 g,到达新状态的步数
                        get_h(next_s), // 新节点的 h,预估代价
                        next_s         // 新节点的 s,新状态
                    }); */
            }
        }
    }

    return 0;
}