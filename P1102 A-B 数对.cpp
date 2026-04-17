// https://www.luogu.com.cn/problem/P1102
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    ll n, c;
    scanf("%lld%lld", &n, &c);
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &nums[i]);
    }
    ll count = 0;
    ll l = 0, r = 1;
    sort(nums.begin(), nums.end());
    while (r < n && l < r)
    {
        if (nums[r] - nums[l] > c)
        {
            l++;
        }
        else if (nums[r] - nums[l] < c)
        {
            r++;
        }
        else
        {
            ll lc = 1;
            ll rc = 1;
            while (nums[l + 1] == nums[l])
            {
                lc++;
                l++;
            }
            while (r < n - 1 && nums[r] == nums[r + 1])
            {
                rc++;
                r++;
            }
            count += lc * rc;
            l++;
            r++;
        }
    }
    cout << count;
    return 0;
}