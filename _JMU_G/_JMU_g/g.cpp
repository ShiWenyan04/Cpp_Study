#include <iostream>
#include <string>
#include<vector>
/*当 你 被 僵 尸 袭 击 的 时 候 ， 你 的 第 一 想 法 一 定 是 打 电 话 报 警 。
传 统 按 键 手 机 的 键 位 通 常 是 这 样 分 布 的 ：
我 们 定 义 两 个 键 位 的 距 离 是 它 们 的 曼 哈 顿 距 离 ， 即 手 指 只 能 在 电 话
键 盘 内 横 向 移 动 一 格 或 纵 向 移 动 一 格 的 情 况 下 ， 从 一 个 键 位 到 另 一
个 键 位 的 最 小 移 动 步 数 。 例 如 ， 号 键 和 号 键 的 距 离 是 ， 和 号 键
的 距 离 也 是 ， 和 号 键 的 距 离 则 是 。*/
using namespace std;

int main() {
	string phonenumber;
	cin >> phonenumber;
	vector<vector< int> >  g = { {3,1}, {0,0} , {0,1}, {0,2},{1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2} };//模拟数字按键的位置索引
	int dis = 0;
	if (phonenumber.size() <= 1) {//当只输入一个数字时，答案为0
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < phonenumber.size(); i++) {//遍历数字
		int prev = phonenumber[i-1]-'0';//第一个数字
		int  curr = phonenumber[i]-'0';//第二个数字
		int x1 = g[prev][0];//第一个数字对应的索引
		int y1 = g[prev][1];
		int x2 = g[curr][0];//第二个数字对应的索引
		int y2 = g[curr][1];
		int distance = abs(x1 - x2) + abs(y1 - y2);//两个按键之间距离
		dis += distance;//累加即为答案
	}
	cout << dis << endl;
	 return 0;
}