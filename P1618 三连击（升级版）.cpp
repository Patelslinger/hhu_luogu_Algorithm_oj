// https: // www.luogu.com.cn/problem/P1618

#include <iostream>
using namespace std;
bool usd[10] = {false};

bool check(int num)
{
    int p = num / 100;
    int q = num % 100 / 10;
    int r = num % 10;

    if (p == q || p == r || q == r || usd[p] || usd[q] || usd[r] || p * q * r == 0 || num < 100 || num > 999)
    {
        return false;
    }
    else
    {
        usd[p] = true;
        usd[q] = true;
        usd[r] = true;
        return true;
    }
}

void clear()
{
    for (int i = 0; i < 10; i++)
    {
        usd[i] = false;
    }
}
int main()
{
    int a, b, c;
    bool has = false;
    cin >> a >> b >> c;

    if (a == 0 || c == 999)
    {
        cout << "No!!!";
        return 0;
    }

    for (int i = 123; i <= 987; i++)
    {
        if (check(i))
        {

            if ((i * b) % a == 0)
            {
                int num2 = i * b / a;
                if (check(num2))
                {
                    if ((i * c) % a == 0)
                    {
                        int num3 = i * c / a;
                        if (check(num3))
                        {
                            cout << i << " " << num2 << " " << num3 << endl;
                            has = true;
                        }
                    }
                }
            }
        }
        clear();
    }
    if (!has)
    {
        cout << "No!!!";
    }

    return 0;
}