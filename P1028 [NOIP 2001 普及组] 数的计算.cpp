// https://www.luogu.com.cn/problem/P1028
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> num(n + 1);
    num[0] = 0;
    num[1] = 1;
    num[2] = 2;
    num[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            num[i] = num[i - 1] + num[i / 2];
        }
        else
        {
            num[i] = num[i - 1];
        }
    }
    cout << num[n];
    return 0;
}