#include <iostream>
#include <vector>
#include <algorithm>
/*假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是满足尽可能多的孩子，并输出这个最大数值。

 */
using namespace std;
/*排序 + 双指针 + 贪心*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int n = g.size(), m = s.size();
        for (int i = 0,j = 0; i < n && j <m; i++,j++) {
            while (j < m && g[i]  > s[j]) {
                j++;
            }
            if (j < m) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> g = { 1,2 };
    vector<int> s = { 1,2,3 };
    Solution so;
    cout << so.findContentChildren(g, s) << endl;
}