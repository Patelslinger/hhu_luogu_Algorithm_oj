// https : // www.luogu.com.cn/problem/P14063
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
struct field
{
    ll single_value;
    ll total_value;
};

int main()
{
    int N, B;
    cin >> N >> B;
    vector<field> A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i].single_value);
        A[i].total_value = A[i].single_value + (i > 0 ? A[i - 1].total_value : 0);
    }
    int l = 0;
    int max_l = 0;
    for (int r = 0; r < N; r++)
    {
        ll sum = A[r].total_value - (l > 0 ? A[l - 1].total_value : 0);
        while (sum > B)
        {
            l++;
            sum = A[r].total_value - (l > 0 ? A[l - 1].total_value : 0);
        }
        max_l = max(max_l, r - l + 1);
    }
    cout << max_l << endl;
    return 0;
}