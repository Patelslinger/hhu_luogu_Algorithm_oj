// https://www.luogu.com.cn/problem/P1464
#include <iostream>
using namespace std;

#define ll long long
ll m[21][21][21] = {0};

ll getw(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else
    {
        if (a > 20 || b > 20 || c > 20)
        {
            if (m[20][20][20] == 0)
            {

                ll num = getw(20, 20, 20);
                m[20][20][20] = num;
                return num;
            }
            return m[20][20][20];
        }
        else
        {
            if (a < b && b < c)
            {
                if (m[a][b][c] == 0)
                {
                    ll num1 = (m[a][b][c - 1] == 0) ? getw(a, b, c - 1) : m[a][b][c - 1];
                    m[a][b][c - 1] = num1;
                    ll num2 = (m[a][b - 1][c - 1] == 0) ? getw(a, b - 1, c - 1) : m[a][b - 1][c - 1];
                    m[a][b - 1][c - 1] = num2;
                    ll num3 = (m[a][b - 1][c] == 0) ? getw(a, b - 1, c) : m[a][b - 1][c];
                    m[a][b - 1][c] = num3;

                    m[a][b][c] = num1 + num2 - num3;
                }
                return m[a][b][c];
            }
            else
            {
                if (m[a][b][c] == 0)
                {
                    ll num1 = (m[a - 1][b][c] == 0) ? getw(a - 1, b, c) : m[a - 1][b][c];
                    m[a - 1][b][c] = num1;

                    ll num2 = (m[a - 1][b - 1][c] == 0) ? getw(a - 1, b - 1, c) : m[a - 1][b - 1][c];
                    m[a - 1][b - 1][c] = num2;

                    ll num3 = (m[a - 1][b][c - 1] == 0) ? getw(a - 1, b, c - 1) : m[a - 1][b][c - 1];
                    m[a - 1][b][c - 1] = num3;

                    ll num4 = (m[a - 1][b - 1][c - 1] == 0) ? getw(a - 1, b - 1, c - 1) : m[a - 1][b - 1][c - 1];
                    m[a - 1][b - 1][c - 1] = num4;

                    m[a][b][c] = num1 + num2 + num3 - num4;
                }
                return m[a][b][c];
            }
        }
    }
}

int main()
{
    ll a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            return 0;
        }
        else
        {
            ll ans = getw(a, b, c);
            printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);
        }
    }
    return 0;
}
