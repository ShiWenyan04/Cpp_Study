#include<iostream>
#include<queue>
/*给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
示例 1:
输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
示例 2:
输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]*/
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue < tuple<int, int, int > > q;//优先队列存储的是一个三元组
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < min(n,k); i++) {// 至多 k 个
            q.emplace(nums1[i] - nums2[0],i,0);// 取相反数变成小顶堆
        }
        //优先队列默认是最大堆，为了能够弹出最小的元素，需要将和取负
        //由于（0，1）和（1，0）会涉及到重复取值，所以默认规定取（1，0）诸如此类

        

        vector<vector<int>> ans;
        while (ans.size() < k) {
            auto [sum, i, j] = q.top();
            q.pop();//每次从堆中弹1个元素，这个元素对应一个最小和的配对（i，j）
            ans.push_back({ nums1[i],nums2[j] });//添加配对索引到ans中
            if (j + 1 < m) {//nums2中配对的第二个元素是否已经用完，未用完就组合新的 即（nums[i],nums[j+1])。 
                q.emplace(-nums1[i] - nums2[j + 1], i, j + 1);
            }
        }
        return ans;
    }
};
int main() {
    int k = 3;
    vector<int> nums1 = { 1,7,11 };
    vector<int> nums2 = { 2,4,6 };
    Solution s;
    vector<vector<int>> ans = s.kSmallestPairs(nums1, nums2, k);
    for (vector<int> v : ans) {
        cout << "[" << endl;
        cout<< v[0] << ","<<v[1] << endl;
        cout << "]" << endl;
        
    }
    return 0;
}
