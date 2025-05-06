#include <iostream>
#include <vector>
/*����һ�� �� 0 ��ʼ������ nums���±�Ҳ�� 0 ��ʼ�������㹹��һ�� ͬ������ ������ ans ��
���У�����ÿ�� i��0 <= i < nums.length���������� ans[i] = nums[nums[i]] ��
���ع����õ����� ans ��
�� 0 ��ʼ������ nums ��һ���� 0 �� nums.length - 1��0 �� nums.length - 1 Ҳ�������ڣ��Ĳ�ͬ������ɵ����顣
ʾ�� 1��
���룺nums = [0,2,1,5,3,4]
�����[0,1,2,4,5,3]*/
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