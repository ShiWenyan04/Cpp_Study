#include <iostream>

using namespace std;


long long gcd(long long a, long long b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		int tg = gcd(a, b);//用韦恩图画图表示。
		//x肯定是b的因数，但不是a的因数，
		//所以求出b中是a的因数的数
		while (gcd(tg, b) != 1) {
			b /= tg;
			tg = gcd(tg, b);
		}
		if (b == 1) {
			cout << -1 << endl;
		}
		else {
			cout << b << endl;
		}
	}
	return 0;
}

