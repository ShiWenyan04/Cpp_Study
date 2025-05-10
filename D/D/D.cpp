#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int j = 0; j < n; j++) {
		cin >> b[j];
	}

	int max_k = 1000000;

	int ans = INT_MAX;// 初始化最小成本为最大值

	// 遍历每一个可能的k值
	for (int k = 0; k < max_k; k++) {
		int val = 0;
		for (int i = 0; i < n; i++) {
			int num = a[0] + i * k;
			if (num != a[i]) {
				val += b[i];
			}
		}
		ans = min(ans, val);
	}
	cout << ans << endl;
}