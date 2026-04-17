// https://www.luogu.com.cn/problem/P2249
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int tar;
        scanf("%d", &tar);
        int l = 0;
        int r = a.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (tar < a[mid])
            {
                r = mid - 1;
            }
            else if (tar > a[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        if (l < a.size() && a[l] == tar)

        {
            printf("%d ", l + 1);
        }
        else
        {
            printf("-1 ");
        }
    }
    return 0;
}