#include<iostream>
using namespace std;
double k, n, m;//����������
long long ans;//�𰸣����ܻ�ը int
double opt = 1.00000;//��������С�������
int main()
{
    cin >> n >> m;
    k = n * opt / -m;//���� k
    for (int i = 0; i < (int)m; i++)//�� 1~m����Ȼ���� (int) Ҳ����
    {
        double t = n + (2 * i + 1) * k / 2;//���Ժ�����ι�ʽ
        t += 0.5;//��������
        ans += (long long)t;//ǿ��ת���� long long ���͡�ʵ�⣺ת���� int Ҳ���ԡ�
    }
    cout << ans;//���
    return 0;
}