#include <iostream>
#include <string>
#include<vector>
/*�� �� �� �� ʬ Ϯ �� �� ʱ �� �� �� �� �� һ �� �� һ �� �� �� �� �� �� �� ��
�� ͳ �� �� �� �� �� �� λ ͨ �� �� �� �� �� �� �� ��
�� �� �� �� �� �� �� λ �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ָ ֻ �� �� �� ��
�� �� �� �� �� �� �� һ �� �� �� �� �� �� һ �� �� �� �� �� �� �� һ �� �� λ �� �� һ
�� �� λ �� �� С �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��
�� �� �� Ҳ �� �� �� �� �� �� �� �� �� �� ��*/
using namespace std;

int main() {
	string phonenumber;
	cin >> phonenumber;
	vector<vector< int> >  g = { {3,1}, {0,0} , {0,1}, {0,2},{1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2} };//ģ�����ְ�����λ������
	int dis = 0;
	if (phonenumber.size() <= 1) {//��ֻ����һ������ʱ����Ϊ0
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < phonenumber.size(); i++) {//��������
		int prev = phonenumber[i-1]-'0';//��һ������
		int  curr = phonenumber[i]-'0';//�ڶ�������
		int x1 = g[prev][0];//��һ�����ֶ�Ӧ������
		int y1 = g[prev][1];
		int x2 = g[curr][0];//�ڶ������ֶ�Ӧ������
		int y2 = g[curr][1];
		int distance = abs(x1 - x2) + abs(y1 - y2);//��������֮�����
		dis += distance;//�ۼӼ�Ϊ��
	}
	cout << dis << endl;
	 return 0;
}