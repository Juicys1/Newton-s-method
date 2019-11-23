#include <stdio.h>

double equation_root(int a, int b, int c, int d);

double f(int a, int b, int c, int d, double x);

double k(int a, int b, int c, int d, double x);

double delta_x(int a, int b, int c, int d, double x);

int main(void)
{
    int a, b, c, d;
    printf("Input the a, b, c and d:\n");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%.2f", equation_root(a, b, c, d));
    return 0;
}

double f(int a, int b, int c, int d, double x)          //求函数值
{
    return a*x*x*x + b*x*x + c*x + d;
}

double k(int a, int b, int c, int d, double x)          //求斜率
{
    return 3*a*x*x + 2*b*x + c;
}

double delta_x(int a, int b, int c, int d, double x)    //求迭代变化值
{
    return f(a, b, c, d, x) / k(a, b, c, d, x);
}

double equation_root(int a, int b, int c, int d)        //求根
{
    double i = 1;
    while(k(a, b, c, d, i) == 0)                        //验证斜率，若等于零则改变i的值
    {
        i++;
    }

    while(f(a, b, c, d, i) * f(a, b, c, d, i - 10e-5) > 0 && f(a, b, c, d, i) * f(a, b, c, d, i + 10e-5) > 0)
        //若i到i - 10e5 或 i到i + 10e5间有根，则退出循环
    {
        i -= delta_x(a, b, c, d, i);
        while(k(a, b, c, d, i) == 0)
        {
            i++;
        }
    }
    return i;
}