#include < iostream>
#include <vector>
/*给你一个整数数组 nums ，请你返回长度为 3 的 子数组 的数量，满足第一个数和第三个数的和恰好为第二个数的一半。
子数组 指的是一个数组中连续 非空 的元素序列。
示例 1：
输入：nums = [1,2,1,4,1]
输出：1
解释：
只有子数组 [1,4,1] 包含 3 个元素且第一个和第三个数字之和是中间数字的一半。number.*/
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {//普通暴力解决
        int ans = 0;
        for (int i = 0; i < nums.size()-2; i++)
        {
            if((nums[i+2] +nums[i]) *2 == nums[i+1]){//题目要求
                ans++;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = { 1,2,1,4,1 };
    Solution s;
    cout << s.countSubarrays(nums) << endl;
}