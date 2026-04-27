// https://www.luogu.com.cn/problem/P11204
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (m < n)
        {
            cout << "No" << endl;
            continue;
        }
        if (m % n == 0)
        {
            cout << "Yes" << endl;
            continue;
        }
        if (m / n == 1 && m % n < n - 1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}