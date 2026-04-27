// https://www.luogu.com.cn/problem/B2165
#include <iostream>
#include <stack>
#include <cstdio> // 包含getchar的头文件

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        stack<char> s; // 每组测试用例重新创建栈，避免残留
        char c;
        bool is_valid = true; // 标记当前用例是否匹配

        // 读取一行字符，直到换行符
        while ((c = getchar()) != '\n')
        {
            // 跳过空白字符（如空格，根据需求可选）
            if (c == ' ')
                continue;

            if (c == '(' || c == '[' || c == '{')
            {
                s.push(c); // 左括号入栈
            }
            else if (c == ')' || c == ']' || c == '}')
            {
                // 遇到右括号，栈为空则直接不匹配
                if (s.empty())
                {
                    is_valid = false;
                    // 读取完当前行剩余字符，避免影响下一组
                    while ((c = getchar()) != '\n')
                        ;
                    break;
                }

                char top = s.top();
                // 匹配则出栈，不匹配则标记为无效
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{'))
                {
                    s.pop();
                }
                else
                {
                    is_valid = false;
                    // 读取完当前行剩余字符
                    while ((c = getchar()) != '\n')
                        ;
                    break;
                }
            }
        }

        // 最终判断：匹配有效 且 栈为空（无残留左括号）
        if (is_valid && s.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}