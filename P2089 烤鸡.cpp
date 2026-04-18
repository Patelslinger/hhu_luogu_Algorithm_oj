// https://www.luogu.com.cn/problem/P2089
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 10 || n > 30)
    {
        cout << 0;
        return 0;
    }
    queue<vector<int>> ans;
    for (int a = 1; a < 4; a++)
    {
        for (int b = 1; b < 4; b++)
        {
            for (int c = 1; c < 4; c++)
            {
                for (int d = 1; d < 4; d++)
                {
                    for (int e = 1; e < 4; e++)
                    {
                        for (int f = 1; f < 4; f++)
                        {
                            for (int g = 1; g < 4; g++)
                            {
                                for (int h = 1; h < 4; h++)
                                {
                                    for (int i = 1; i < 4; i++)
                                    {
                                        for (int j = 1; j < 4; j++)
                                        {
                                            if (a + b + c + d + e + f + g + h + i + j == n)
                                            {
                                                vector<int> s = {a, b, c, d, e, f, g, h, i, j};
                                                ans.push(s);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    while (!ans.empty())
    {
        vector<int> s = ans.front();
        for (auto i : s)
        {
            cout << i << " ";
        }
        cout << endl;
        ans.pop();
    }
    return 0;
}