// https://www.luogu.com.cn/problem/P1044
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 2;
    nums[3] = 5;
    for (int i = 4; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            nums[i] += nums[j] * nums[i - j - 1];
        }
    }
    cout << nums[n];
    return 0;
}