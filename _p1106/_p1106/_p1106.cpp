#include <iostream>
#include <string>
#include  <algorithm>

/*��������һ���߾��ȵ������� n�������� 250 λ����ȥ���������� k �����ֺ�ʣ�µ����ְ�ԭ���Ҵ������һ���µķǸ�������
��̶Ը����� n �� k��Ѱ��һ�ַ���ʹ��ʣ�µ�������ɵ�������С��
�����ʽ
����������������
��һ������һ���߾��ȵ������� n��
�ڶ�������һ�������� k����ʾ��Ҫɾ�������ָ�����
�����ʽ
���һ�����������ʣ�µ���С����*/
using namespace std;

int main() {
	string  n;
	cin >> n;
	int k;
	cin >> k;
	int len = n.size();
	
	while (k > 0) {
		int i = 0;
		while (i < len - 1 && n[i] <= n[i + 1]) {
			i++;
		}
		n.erase(i,1);
		k--;
	}
	while (n.size() > 1 && n[0] == '0') {
		n.erase(0, 1);
	}
	cout << n << endl;
}
