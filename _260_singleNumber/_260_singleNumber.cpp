#include <iostream>
#include <unordered_map>

using namespace std;
/*给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。

 

示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。*/

class Solution {
public :
	vector<int> singleNumber(vector<int>& nums) {
		unordered_map <int,int> map;
		for (int i : nums) {//存次数
			map[i]++;
		}
		vector<int> ans;
		for (const auto& [num, occ] : map) {//次数为1 保存答案
			if (occ == 1) {
				ans.push_back(num);
			}
		}
		return ans ;
	}
};

int main() {
	vector<int> nums = { 2,2,1,1,8,3 };

	Solution s;
	vector<int>ans = s.singleNumber(nums);
	for (int i : ans) {
		cout << i << endl;
	}
	
}