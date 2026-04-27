// https://www.luogu.com.cn/problem/P1763
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long
using namespace std;
const int MAXLIM = 110;
const int INF = 1e8;

ll a, b;
vector<ll> ans(MAXLIM, INF);
vector<ll> cur(MAXLIM);
bool find_ans = false;
int limit;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 约分
void reduce(ll &a, ll &b)
{
    ll g = gcd(a, b);
    a /= g;
    b /= g;
}

// dfs :剩余要分解的项数
// c,d :当前要分解的分数c/d
// last:上一个分母
void dfs(int depth, ll c, ll d, ll last)
{
    if (depth == 2)
    {
        for (ll k = 4 * d / (c * c) + 1;; k++)
        {
            ll delta = k * k * c * c - 4 * k * d;
            if (delta <= 0)
            {
                continue;
            }
            ll t = sqrt(delta);
            ll x = (k * c - t) / 2;
            ll y = (k * c + t) / 2;
            if (y > ans[1])
                break;
            if (t * t != delta || (k * c - t) % 2 != 0 || x <= last)
                continue;
            ans = cur;
            ans[2] = x;
            ans[1] = y;
            find_ans = true;
        }
        return;
    }
    ll maxe = min(depth * d / c, ans[1] - 1); // 下界:必须大于上一个分母
    ll mine = max(last, d / c) + 1;           // 上界:剪枝优化
    // 枚举分母
    for (ll i = mine; i <= maxe; i++)
    {
        // 计算剩余分数 : c/d - 1/i = (c*i - d) / (d*i)
        ll nd = d * i;
        ll nc = c * i - d;
        reduce(nc, nd);
        cur[depth] = i;
        dfs(depth - 1, nc, nd, i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    reduce(a, b);
    if (a == 1)
    {
        cout << b;
    }
    else
    {
        for (limit = 2; limit < MAXLIM; limit++)
        {
            find_ans = false;
            dfs(limit, a, b, 0);
            if (find_ans)
                break;
        }
        for (int i = limit; i >= 1; i--)
        {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}