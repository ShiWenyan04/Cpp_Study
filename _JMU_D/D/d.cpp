#include <iostream>
#include <vector>
#include <algorithm>
/*在 病 毒 解 药 的 合 成 中 ， 有 一 个 步 骤 需 要 量 取 适 量 的 试 剂 ， 然 而 由 于
近 期 保 护 伞 公 司 忙 于 处 理 生 化 危 机 事 件 ， 因 此 经 费 紧 张 买 不 起 量
筒 ， 只 能 用 现 有 的 器 材 将 就 一 下 。
现 有 的 器 材 只 有 个 试 管 和 一 个 容 量 为 无 穷 大 的 烧 杯 ， 第 个 试 管 的
容 量 为 毫 升 ， 你 需 要 利 用 这 些 器 材 精 确 量 取 毫 升 的 试 剂 。
更 具 体 地 说 ， 你 只 能 进 行 如 下 操 作 ：
1 . 选 择 一 个 试 管 ， 将 毫 升 试 剂 注 入 烧 杯 ， 由 于 保 护 伞 公 司 曾 经 财
大 气 粗 ， 这 个 操 作 可 以 进 行 任 意 次 。
2 . 选 择 一 个 试 管 ， 舀 出 烧 杯 中 的 毫 升 试 剂 倒 回 储 存 罐 ， 若 烧 杯 中
的 试 剂 不 够 了 就 全 部 倒 空 。 （ 请 注 意 ， 真 实 的 化 学 实 验 中 请 不 要 把
倒 出 来 的 试 剂 再 倒 回 去 ！ ）
最 后 烧 杯 中 能 否 恰 好 剩 下 毫 升 液 体 ？
由 于 保 护 伞 公 司 需 要 进 行 多 次 实 验 ， 因 此 本 题 有 多 组 询 问 需 要 回
答 。*/
using namespace std;
//由题可知，试管容量的最小公约数的倍数可被测量


long long  gcd(long long  a, long long  b) {//最小公约数
	while (b != 0) {
		long long temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);//提高输入输出的速度
	cin.tie(nullptr);//提高输入输出的速度

	int n, q;
	cin >> n >> q;
	vector<long long> nums(n);
	for (int i = 0; i < n; i++) {//试管容量
		cin >> nums[i];
	}
	long long g = nums[0];//求试管的最小公约数
	for (int i =1 ; i < n; i++) {
		g = gcd(g, nums[i]);
	}
	
	while(q--) {//枚举每个目标数值
		long long v;
		cin >> v;
		if (v %g == 0) {//目标数值可以被测量出来
			cout << "Yes" << endl;
		}
		else {//不能测量
			cout << "No" << endl;
		}
	}
}