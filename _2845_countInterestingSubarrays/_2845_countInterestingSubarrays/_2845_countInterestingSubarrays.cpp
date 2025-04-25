#include<iostream>
#include<vector>
#include<unordered_map>
/*给你一个下标从 0 开始的整数数组 nums ，以及整数 modulo 和整数 k 。
请你找出并统计数组中 趣味子数组 的数目。
如果 子数组 nums[l..r] 满足下述条件，则称其为 趣味子数组 ：
在范围 [l, r] 内，设 cnt 为满足 nums[i] % modulo == k 的索引 i 的数量。并且 cnt % modulo == k 。
以整数形式表示并返回趣味子数组的数目。
注意：子数组是数组中的一个连续非空的元素序列。
示例 1：
输入：nums = [3,2,4], modulo = 2, k = 1
输出：3
解释：在这个示例中，趣味子数组分别是： 
子数组 nums[0..0] ，也就是 [3] 。 
- 在范围 [0, 0] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
子数组 nums[0..1] ，也就是 [3,2] 。
- 在范围 [0, 1] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
子数组 nums[0..2] ，也就是 [3,2,4] 。
- 在范围 [0, 2] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
可以证明不存在其他趣味子数组。因此，答案为 3 。
示例 2：
输入：nums = [3,1,9,6], modulo = 3, k = 0
输出：2
解释：在这个示例中，趣味子数组分别是： 
子数组 nums[0..3] ，也就是 [3,1,9,6] 。
- 在范围 [0, 3] 内，只存在 3 个下标 i = 0, 2, 3 满足 nums[i] % modulo == k 。
- 因此 cnt = 3 ，且 cnt % modulo == k 。
子数组 nums[1..1] ，也就是 [1] 。
- 在范围 [1, 1] 内，不存在下标满足 nums[i] % modulo == k 。
- 因此 cnt = 0 ，且 cnt % modulo == k 。
可以证明不存在其他趣味子数组，因此答案为 2 。
 */
using namespace std;

/*设 sum[i] 表示数组 nums 从 0 到 i 中出现满足 x%m=k 的数目
*  nums[l..r] 出现的特殊元素的数目为   sum[r]−sum[l−1] 则有：(sum[r]−sum[l−1])modmodulo=k
移项得： (sum[r]-k +m)%m  =  sum[l−1]%m

故我们可以先用map存  左式  的数目，然后再找出满足 右式 的 并 累加 即可
*/
class Solution {
public :
	long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
		int n = nums.size();
		vector<int> a(n+1);
		vector<int>b(n + 1);
		for (int i = 1; i <= n; i++) {//计算每一个num是否可以满足条件，如果满足条件那么相对的a数组就会变为1；
			if (nums[i-1] % m == k) {//由于题目要求cnt%m=k   cnt可以由 sum[j]-sum[i]求得
				a[i] = 1;
			}
			b[i] = b[i - 1] + a[i ];//上文提到的sum为b数组
		}

		unordered_map<int, int > map;
		map[0]=1;
		long long  ans = 0;
		for (int i = 1; i <= n; i++) {//遍历前缀和
			//计算当前前缀和对 modulo 取余数。
			//找到哪些前缀和 b[j]，满足(b[i] - b[j]) % modulo == k
			int t = map[(b[i] + m - k) % m];
			ans += t;//左式累加
			map[b[i] % m]++;//右式更新
		}
		return ans;
	}
};
int main() {
	vector<int>nums = { 3,2,4 };
	int m = 2;
	int k = 1;
	Solution s;
	cout << s.countInterestingSubarrays(nums, m, k) << endl;
}