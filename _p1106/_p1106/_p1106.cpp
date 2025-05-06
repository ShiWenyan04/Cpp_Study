#include <iostream>
#include <string>
#include  <algorithm>

/*键盘输入一个高精度的正整数 n（不超过 250 位），去掉其中任意 k 个数字后剩下的数字按原左右次序将组成一个新的非负整数。
编程对给定的 n 和 k，寻找一种方案使得剩下的数字组成的新数最小。
输入格式
输入两行正整数。
第一行输入一个高精度的正整数 n。
第二行输入一个正整数 k，表示需要删除的数字个数。
输出格式
输出一个整数，最后剩下的最小数。*/
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
