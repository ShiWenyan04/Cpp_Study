#include <iostream>
#include <vector>
#include <algorithm>
/*���ڸ��� oj ���� n ��������ÿ�������Ŀ�ʼ��������ʱ�����֪���ġ�

yyy ��Ϊ���μ�Խ��ı�����noip ���ܿ���Խ�ã��ٵģ���

���ԣ�����֪��������ܲμӼ���������

���� yyy ���X�m�����Ҫ�μ�һ������������ʼ���գ����Ҳ���ͬʱ�μ� 2 �������ϵı�����*/
using namespace std;
int n;
struct node {
	int st;//��ʼʱ��
	int end;//����ʱ��
}com[1000007];

bool compare(node x, node y) {
	if (x.end != y.end) return x.end < y.end;//������ʱ�������ǰ
	else return x.st > y.st;//����ʼʱ�������ǰ
}

int ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> com[i].st >> com[i].end;//����
	}
	sort(com + 1, com+ n + 1, compare);//����������
	int end = -1;//��ֵ
	for (int i = 1; i <= n; i++) {
		if (com[i].st >= end) {//��ʼʱ���Ŀǰʱ����ans++������Ŀǰ�Ľ���ʱ��
			ans++;
			end = com[i].end;
		}
	}
		cout << ans << endl;
		return 0;
}