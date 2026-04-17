// https://www.luogu.com.cn/problem/P1255
#include <iostream>
#include <string>
using namespace std;
string add(string s1, string s2)
{
    int jw = 0;
    string ans = "";
    while (!s1.empty() || !s2.empty() || jw)
    {

        int num1 = 0, num2 = 0;
        if (!s1.empty())
        {
            num1 = s1.back() - '0';
            s1.pop_back();
        }
        if (!s2.empty())
        {
            num2 = s2.back() - '0';
            s2.pop_back();
        }
        int sum = num1 + num2 + jw;
        jw = sum / 10;
        ans += '0' + (sum % 10);
    }
    for (int i = 0; i < ans.length() / 2; i++)
    {
        swap(ans[i], ans[ans.length() - 1 - i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string s1 = "1", s2 = "2";
    string ans = "";
    if (n == 1)
    {
        cout << s1;
    }
    else if (n == 2)
    {
        cout << s2;
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            s1 = add(s1, s2);
            swap(s1, s2);
            ans = s2;
        }
        cout << ans;
    }
    return 0;
}