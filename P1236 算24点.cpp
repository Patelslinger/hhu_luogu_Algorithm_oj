// https://www.luogu.com.cn/problem/P1236
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 存储运算步骤的结构体
struct Step
{
    int a, b;
    char op;
    int res;
    string str; // 步骤的字符串形式（如 "7*3=21"）
};

vector<Step> steps; // 存储最终的3步运算

// 运算函数：返回运算结果，若不合法（除零/非整数/结果为负）返回-1
int calc(int a, int b, char op)
{
    int res = -1;
    switch (op)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        // 减法必须保证a > b，结果为正
        if (a > b)
            res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        // 除法必须保证b≠0、a能被b整除、结果为正
        if (b != 0 && a % b == 0 && a / b > 0)
        {
            res = a / b;
        }
        break;
    default:
        res = -1;
    }
    // 所有运算结果必须为正整数
    return (res > 0) ? res : -1;
}

// 格式化步骤字符串（保证大数在前）
string format_step(int a, int b, char op, int res)
{
    // 对于加减乘，保证大数在前；除法需要保证被除数>除数且能整除（已在calc中检查）
    if ((op == '+' || op == '*') && a < b)
    {
        swap(a, b);
    }
    // 减法和除法强制大数在前（已在calc中保证a>b）
    if ((op == '-' || op == '/') && a < b)
    {
        swap(a, b);
    }
    return to_string(a) + op + to_string(b) + "=" + to_string(res);
}

// 检查运算顺序1: ((a op1 b) op2 c) op3 d
bool check1(vector<int> nums, vector<char> ops)
{
    // 第一步：a op1 b
    int res1 = calc(nums[0], nums[1], ops[0]);
    if (res1 == -1)
        return false;
    Step s1 = {nums[0], nums[1], ops[0], res1, format_step(nums[0], nums[1], ops[0], res1)};

    // 第二步：res1 op2 c
    int res2 = calc(res1, nums[2], ops[1]);
    if (res2 == -1)
        return false;
    Step s2 = {res1, nums[2], ops[1], res2, format_step(res1, nums[2], ops[1], res2)};

    // 第三步：res2 op3 d
    int res3 = calc(res2, nums[3], ops[2]);
    if (res3 == 24)
    {
        Step s3 = {res2, nums[3], ops[2], res3, format_step(res2, nums[3], ops[2], res3)};
        steps = {s1, s2, s3};
        return true;
    }
    return false;
}

// 检查运算顺序2: (a op1 (b op2 c)) op3 d
bool check2(vector<int> nums, vector<char> ops)
{
    // 第一步：b op2 c
    int res1 = calc(nums[1], nums[2], ops[1]);
    if (res1 == -1)
        return false;
    Step s1 = {nums[1], nums[2], ops[1], res1, format_step(nums[1], nums[2], ops[1], res1)};

    // 第二步：a op1 res1
    int res2 = calc(nums[0], res1, ops[0]);
    if (res2 == -1)
        return false;
    Step s2 = {nums[0], res1, ops[0], res2, format_step(nums[0], res1, ops[0], res2)};

    // 第三步：res2 op3 d
    int res3 = calc(res2, nums[3], ops[2]);
    if (res3 == 24)
    {
        Step s3 = {res2, nums[3], ops[2], res3, format_step(res2, nums[3], ops[2], res3)};
        steps = {s1, s2, s3};
        return true;
    }
    return false;
}

// 检查运算顺序3: (a op1 b) op2 (c op3 d)
bool check3(vector<int> nums, vector<char> ops)
{
    // 第一步：a op1 b
    int res1 = calc(nums[0], nums[1], ops[0]);
    if (res1 == -1)
        return false;
    Step s1 = {nums[0], nums[1], ops[0], res1, format_step(nums[0], nums[1], ops[0], res1)};

    // 第二步：c op3 d
    int res2 = calc(nums[2], nums[3], ops[2]);
    if (res2 == -1)
        return false;
    Step s2 = {nums[2], nums[3], ops[2], res2, format_step(nums[2], nums[3], ops[2], res2)};

    // 第三步：res1 op2 res2
    int res3 = calc(res1, res2, ops[1]);
    if (res3 == 24)
    {
        Step s3 = {res1, res2, ops[1], res3, format_step(res1, res2, ops[1], res3)};
        steps = {s1, s2, s3};
        return true;
    }
    return false;
}

// 检查运算顺序4: a op1 ((b op2 c) op3 d)
bool check4(vector<int> nums, vector<char> ops)
{
    // 第一步：b op2 c
    int res1 = calc(nums[1], nums[2], ops[1]);
    if (res1 == -1)
        return false;
    Step s1 = {nums[1], nums[2], ops[1], res1, format_step(nums[1], nums[2], ops[1], res1)};

    // 第二步：res1 op3 d
    int res2 = calc(res1, nums[3], ops[2]);
    if (res2 == -1)
        return false;
    Step s2 = {res1, nums[3], ops[2], res2, format_step(res1, nums[3], ops[2], res2)};

    // 第三步：a op1 res2
    int res3 = calc(nums[0], res2, ops[0]);
    if (res3 == 24)
    {
        Step s3 = {nums[0], res2, ops[0], res3, format_step(nums[0], res2, ops[0], res3)};
        steps = {s1, s2, s3};
        return true;
    }
    return false;
}

// 检查运算顺序5: a op1 (b op2 (c op3 d))
bool check5(vector<int> nums, vector<char> ops)
{
    // 第一步：c op3 d
    int res1 = calc(nums[2], nums[3], ops[2]);
    if (res1 == -1)
        return false;
    Step s1 = {nums[2], nums[3], ops[2], res1, format_step(nums[2], nums[3], ops[2], res1)};

    // 第二步：b op2 res1
    int res2 = calc(nums[1], res1, ops[1]);
    if (res2 == -1)
        return false;
    Step s2 = {nums[1], res1, ops[1], res2, format_step(nums[1], res1, ops[1], res2)};

    // 第三步：a op1 res2
    int res3 = calc(nums[0], res2, ops[0]);
    if (res3 == 24)
    {
        Step s3 = {nums[0], res2, ops[0], res3, format_step(nums[0], res2, ops[0], res3)};
        steps = {s1, s2, s3};
        return true;
    }
    return false;
}

// 主函数：枚举所有可能的组合
bool solve(vector<int> nums)
{
    // 枚举4个数字的所有排列
    sort(nums.begin(), nums.end());
    do
    {
        // 枚举3个运算符的所有组合（+、-、*、/）
        vector<char> ops = {'+', '-', '*', '/'};
        for (char op1 : ops)
        {
            for (char op2 : ops)
            {
                for (char op3 : ops)
                {
                    vector<char> op_list = {op1, op2, op3};
                    // 检查所有运算顺序
                    if (check1(nums, op_list))
                        return true;
                    if (check2(nums, op_list))
                        return true;
                    if (check3(nums, op_list))
                        return true;
                    if (check4(nums, op_list))
                        return true;
                    if (check5(nums, op_list))
                        return true;
                }
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));
    return false;
}

int main()
{
    vector<int> nums(4);
    for (int i = 0; i < 4; ++i)
    {
        cin >> nums[i];
    }

    if (solve(nums))
    {
        // 输出3步运算
        for (auto &step : steps)
        {
            cout << step.str << endl;
        }
    }
    else
    {
        cout << "No answer!" << endl;
    }

    return 0;
}