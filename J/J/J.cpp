#include<iostream>
using namespace std;
double k, n, m;//浮点数类型
long long ans;//答案：可能会炸 int
double opt = 1.00000;//乘数，减小精度误差
int main()
{
    cin >> n >> m;
    k = n * opt / -m;//计算 k
    for (int i = 0; i < (int)m; i++)//从 1~m，虽然不加 (int) 也可以
    {
        double t = n + (2 * i + 1) * k / 2;//简化以后的梯形公式
        t += 0.5;//四舍五入
        ans += (long long)t;//强制转换成 long long 类型。实测：转换成 int 也可以。
    }
    cout << ans;//输出
    return 0;
}