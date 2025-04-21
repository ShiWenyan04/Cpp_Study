#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int, int>> hashset; // 存储索引
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // 只需要考虑 i < j
                if (nums[i] == nums[j]) {
                    hashset.insert({i, j}); // 使用 pair 插入
                }
            }
        }

        int cnt = 0;
        for (auto& e : hashset) {
            
            if (k != 0 && (e.first * e.second) % k == 0) {
                cnt++;
            }
        }

        return cnt;
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2; 
    Solution s;

    cout << s.countPairs(nums, k) << endl;

    return 0;
}

