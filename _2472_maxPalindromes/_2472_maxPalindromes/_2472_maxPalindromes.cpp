#include <iostream>
#include <vector>
/*给你一个字符串 s 和一个 正 整数 k 。
从字符串 s 中选出一组满足下述条件且 不重叠 的子字符串：
每个子字符串的长度 至少 为 k 。
每个子字符串是一个 回文串 。
返回最优方案中能选择的子字符串的 最大 数目。
子字符串 是字符串中一个连续的字符序列。
示例 1 ：
输入：s = "abaccdbbd", k = 3
输出：2
解释：可以选择 s = "abaccdbbd" 中斜体加粗的子字符串。"aba" 和 "dbbd" 都是回文，且长度至少为 k = 3 。
可以证明，无法选出两个以上的有效子字符串。*/
using namespace std;

class Solution {
public:
	int maxPalindromes(string str, int k) {
		int n = str.size();
		vector<int> f(n + 1);//f[i]表示处理到第i个字符时能够构成的回文子串的最大数量
		for (int i = 0; i < 2 * n + 1; i++) {//目的是遍历回文中心，对于回文中心：
															//1.单字符中心  2双字符中心

			int left = i / 2, right = (i + 1) / 2;//left 和right是当前会问中心的左右边界
																//目的是让i为偶数时表示双字符中心，i为技术时表示单字符中心
			
			f[left + 1] = max(f[left], f[left + 1]);//f[left+1]答案至少是f[left]的答案

			for (; left >= 0 && right <= n - 1 && str[left] == str[right]; right++, left--) {
				//使用 for 循环扩展回文子串的边界，从 left 和 right 开始，
				// 向两边扩展直到 left 和 right 不再匹配，或者超出字符串边界。

				if (right - left + 1 >= k) {
					//如果扩展的回文长度大于等于 k，那么我们可以考虑将该回文计入结果，
					// 因此更新 f[right + 1]
				
					f[right + 1] = max(f[right + 1], f[left] + 1);
				}

			}
		}
		return f[n];
	}
};

			int main() {
			
				string str = "abaccdbbd";
				int k = 3;
				Solution s;
				cout << s.maxPalindromes(str, k) << endl;
			}