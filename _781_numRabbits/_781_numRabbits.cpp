#include<iostream>
#include<vector>
#include<unordered_map>
/*森林中有未知数量的兔子。提问其中若干只兔子 "还有多少只兔子与你（指被提问的兔子）颜色相同?" ，将答案收集到一个整数数组 answers 中，其中 answers[i] 是第 i 只兔子的回答。
给你数组 answers ，返回森林中兔子的最少数量。

输入：answers = [1,1,2]
输出：5
解释：
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。 
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。 
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。 
因此森林中兔子的最少数量是 5 只：3 只回答的和 2 只没有回答的。*/
using namespace std;
/*思路：
现在有 13 只兔子回答 5。假设其中有一只红色的兔子，那么森林中必然有 6 只红兔子。
再假设其中还有一只蓝色的兔子，同样的道理森林中必然有 6 只蓝兔子。
为了最小化可能的兔子数量，我们假设这 12 只兔子都在这 13 只兔子中。
那么还有一只额外的兔子回答 5，这只兔子只能是其他的颜色，
这一颜色的兔子也有 6 只。因此这种情况下最少会有 18 只兔子。
一般地，如果有 x 只兔子都回答 y，则至少有 x/(y+1) 种不同的颜色，且每种颜色有 y+1 只兔子，
因此兔子数至少为x/(y+1)*(y+1)
但是不能整除，所以向上取整(x+y)/(y+1)*(y+1)
*/


class Solution {
public:
	int numRabbits(vector<int>& nums) {
		unordered_map <int, int >map;
		for (auto& x : nums) {//统一回答的兔子个数
			map[x]++;
		}
		int ans = 0;
		for (auto& [x, y] : map) {//计算最少有多少兔子
			ans += (y + x) / (x + 1) * (x + 1);
		}
		return ans;
	}
};
int main() {
	vector<int> nums = { 1,1,2 };
	Solution s;
	cout << s.numRabbits(nums) << endl;
}