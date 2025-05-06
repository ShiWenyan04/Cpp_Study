#include <iostream>
#include <vector>
/*给你一个 从 0 开始的排列 nums（下标也从 0 开始）。请你构建一个 同样长度 的数组 ans ，
其中，对于每个 i（0 <= i < nums.length），都满足 ans[i] = nums[nums[i]] 。
返回构建好的数组 ans 。
从 0 开始的排列 nums 是一个由 0 到 nums.length - 1（0 和 nums.length - 1 也包含在内）的不同整数组成的数组。
示例 1：
输入：nums = [0,2,1,5,3,4]
输出：[0,1,2,4,5,3]*/
using namespace std;

class Solution {
public:
	vector<int>  buildArray(vector<int>& nums) {
		int n = nums.size();
		vector <int> ans;
		for (int i = 0; i < n; i++){
			ans.push_back( nums[nums[i]]);
		}
		return ans;
	}
};

int main() {
	vector<int> nums = { 0,2,1,5,3,4 };
	Solution s;
	nums = s.buildArray(nums);
	for (int i : nums) {
		cout << i << endl;
	}
}