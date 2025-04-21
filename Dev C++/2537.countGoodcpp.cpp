#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;

//给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。
//一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好 子数组。
//子数组 是原数组中一段连续 非空 的元素序列。
//示例 1：
//输入：nums = [1,1,1,1,1], k = 10
//输出：1
///解释：唯一的好子数组是这个数组本身。
//示例 2
//输入：nums = [3,1,4,3,2,2,4], k = 2
//输出：4
//解释：总共有 4 个不同的好子数组：
//- [3,1,4,3,2,2] 有 2 对。
//- [3,1,4,3,2,2,4] 有 3 对。
//- [1,4,3,2,2,4] 有 2 对。
//- [4,3,2,2,4] 有 2 对。
class solution {
public :
	long long countGood(vector<int> & nums,int k){
		int same = 0;//当前区间成对的数量 
		long long ans= 0;//结果 
		int n = nums.size();
		int right = -1, left = 0;//双指针，right为右边界，left为左边界 
		unordered_map<int,int> cnt;//哈希表记录每个数字出现的次数 
		while(left < n){
			while(same < k && right +1 < n){
				right ++;
				same+= cnt[nums[right]];//当前数字如果有重复就增加 
				cnt[nums[right]]++;//右边界的数字计输增加 
			}
			if(same >= k){//当same满足条件 
				ans+=n-right;//从right到n-1的每一个子数组都是有效的 
			}
			cnt[nums[left]]--;//移动左边界，缩小窗口 
			same -= cnt[nums[left]];//移除左边界数字后对数减少 
			left++;//左指针移动 
			
		}
		return ans;	
	}
};

int main ()
{
	vector<int> nums = {3,1,4,3,2,2,4};
	int k = 2;
	solution s; 
	cout << s.countGood(nums,k) << endl;
	return 0;
}

