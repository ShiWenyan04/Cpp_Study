#include <iostream>
#include <vector>
#include <algorithm>
/*现在各大 oj 上有 n 个比赛，每个比赛的开始、结束的时间点是知道的。

yyy 认为，参加越多的比赛，noip 就能考的越好（假的）。

所以，他想知道他最多能参加几个比赛。

由于 yyy 是蒟蒻，如果要参加一个比赛必须善始善终，而且不能同时参加 2 个及以上的比赛。*/
using namespace std;
int n;
struct node {
	int st;//开始时间
	int end;//结束时间
}com[1000007];

bool compare(node x, node y) {
	if (x.end != y.end) return x.end < y.end;//按结束时间早的在前
	else return x.st > y.st;//按开始时间晚的在前
}

int ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> com[i].st >> com[i].end;//输入
	}
	sort(com + 1, com+ n + 1, compare);//按规则排序
	int end = -1;//初值
	for (int i = 1; i <= n; i++) {
		if (com[i].st >= end) {//开始时间比目前时间晚，ans++，更新目前的结束时间
			ans++;
			end = com[i].end;
		}
	}
		cout << ans << endl;
		return 0;
}