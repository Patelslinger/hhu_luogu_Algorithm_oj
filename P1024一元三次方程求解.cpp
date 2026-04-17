// https://www.luogu.com.cn/problem/P1024
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double a, b, c, d;
const double s = 1e-4;

double f(double x)
{
    double num1 = a * x * x * x;
    double num2 = b * x * x;
    double num3 = c * x;
    return num1 + num2 + num3 + d;
}

int main()
{
    cin >> a >> b >> c >> d;
    // 修正：一阶导数 3ax²+2bx+c
    double A = 3 * a;
    double B = 2 * b;
    double C = c;

    double f1 = -100.0;
    double f4 = 100.0;
    double delta = B * B - 4 * A * C;

    double f2 = (-B - sqrt(delta)) / (2 * A);
    double f3 = (-B + sqrt(delta)) / (2 * A);

    bool has = false;

    // 第一段 [-100, f2]
    while (f(f1) * f(f2) < 0 && f2 - f1 > s)
    {
        double mid = (f1 + f2) / 2;
        if (f(mid) * f(f1) > 0)
        {
            f1 = mid;
        }
        else
        {
            f2 = mid;
        }
    }
    cout << fixed << setprecision(2) << f2 << " ";

    // 第二段 [f2, f3]
    has = false;
    while (f(f2) * f(f3) < 0 && f3 - f2 > s)
    {
        double mid = (f3 + f2) / 2;
        if (f(mid) * f(f2) > 0)
        {
            f2 = mid;
        }
        else
        {
            f3 = mid;
        }
    }
    cout << fixed << setprecision(2) << f3 << " ";

    // 第三段 [f3, 100] 修复：f(f1) → f(f3)
    has = false;
    while (f(f3) * f(f4) < 0 && f4 - f3 > s)
    {
        double mid = (f3 + f4) / 2;
        if (f(mid) * f(f3) > 0)
        {
            f3 = mid;
        }
        else
        {
            f4 = mid;
        }
    }
    cout << fixed << setprecision(2) << f4;

    return 0;
}