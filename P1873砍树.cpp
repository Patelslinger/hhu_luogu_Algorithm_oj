// https://www.luogu.com.cn/problem/P1873
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int main()
{
    ll N, M;
    scanf("%lld%lld", &N, &M);
    ll sum = 0;
    vector<ll> woods(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%d", &woods[i]);
    }
    sort(woods.begin(), woods.end());
    ll l = 0;
    ll r = N - 1;
    ll pos = 0;

    while (l <= r)
    {
        sum = 0;
        ll mid = (l + r) / 2;

        for (ll index = mid + 1; index < N; index++)
        {
            sum += woods[index] - woods[mid];
        }
        if (sum >= M) // 砍多了或刚好
        {
            l = mid + 1;
            pos = mid;
        }
        else // 砍少了
        {
            r = mid - 1;
        }
    }

    ll ans = woods[pos];
    ll end = (pos == N - 1) ? woods[pos] : woods[pos + 1];
    for (ll h = woods[pos]; h <= end; h++)
    {
        ll sum = 0;
        for (ll i = pos + 1; i < N; i++)
        {
            sum += woods[i] - h;
        }
        if (sum >= M)
        {
            ans = h;
        }
        else
        {
            break;
        }
    }
    cout << ans;

    return 0;
}