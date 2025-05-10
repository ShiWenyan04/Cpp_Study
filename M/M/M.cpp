#include<iostream>

using namespace std;

int t, n, k;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k == 1)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}