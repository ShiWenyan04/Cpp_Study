#include<iostream>
#include <vector>
/*现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j] 为该位置珠宝的价值。拿取珠宝的规则为：
只能从架子的左上角开始拿珠宝
每次可以移动到右侧或下侧的相邻位置
到达珠宝架子的右下角时，停止拿取
注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame = [[0]]。
示例 1：
输入：frame = [[1,3,1],[1,5,1],[4,2,1]]
输出：12
解释：路径 1→3→5→2→1 可以拿到最高价值的珠宝*/
using namespace std;
//动态规划
class Solution {
public :
	int jewelleryValue(vector<vector<int>>& frame) {
		int n = frame.size();
		int m = frame[0].size();
		for (int i = 1; i < m; i++) {//第一行只能向右累加得到最大值
			frame[0][i] += frame[0][i - 1];
		}
		for (int i = 1; i < n; i++) {//第一列只能向下累加得到最大值
			frame[i][0] += frame[i-1][0];
		}
		for (int i = 1; i < n; i++){//其余均为（i，j）的上方和左方的最大的一个值相加得来
			for (int j = 1; j < m; j++) {
				frame[i][j] += max(frame[i - 1][j], frame[i][j - 1]);
			}
		}
		return frame[n - 1][m - 1];
	}
};
int main() {
	vector<vector<int >> frame = { {1,2} ,{5,6},{1,1} };
	Solution s;
	cout << s.jewelleryValue(frame) << endl;
}