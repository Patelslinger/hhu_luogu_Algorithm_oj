// https://www.luogu.com.cn/problem/P2392

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> temp;
int n, total;
int result; // 某科最少时间
void input(vector<int> &s, int len)
{
    for (int i = 0; i < len; i++)
    {
        cin >> s[i];
    }
}

void dfs(int pos, int now) // pos：当前搜到第几道题 //now:当前左脑用时
{
    if (pos == n)
    {
        // now:左脑用时
        // total-now右脑用时
        result = min(result, max(now, total - now));
        return;
    }
    // 如果不选这题，这题给右脑，左脑时间不变，下一题
    dfs(pos + 1, now);
    // 如果选，左脑时间累加，下一题
    dfs(pos + 1, now + temp[pos]);
}

int gettime(vector<int> s)
{
    temp = s;
    n = s.size();
    total = 0;
    for (int x : s)
    {
        total += x;
    }
    result = 1e6;
    dfs(0, 0);
    return result;
}
int main()
{
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    vector<int> a(s1);
    vector<int> b(s2);
    vector<int> c(s3);
    vector<int> d(s4);
    input(a, s1);
    input(b, s2);
    input(c, s3);
    input(d, s4);
    int sum = gettime(a) + gettime(b) + gettime(c) + gettime(d);
    cout << sum;
    return 0;
}