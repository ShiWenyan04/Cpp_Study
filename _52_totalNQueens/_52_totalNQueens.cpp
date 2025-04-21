#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public :
	int cnt = 0;
	//判断皇后在前面几行出现的位置与当前位置是否冲突
	bool judge(int idx, vector<int>& q) {
		int row = q.size();
		if (row== 0) {//第一行随便放
			return true;
		}
		for (int i = 0; i < row; i++) {//遍历已经放过皇后的位置，是否冲突
			if (q[i] == idx || abs(row - i) == abs(idx - q[i])) {
				return false;
			}
		}
		return true;
	}

	void dfs(int n, vector<int>& q) {
		if (q.size() == n) {//如果皇后放完了，次数加一
			cnt++;
			return;
		}
		for (int i = 0; i < n; i++){//遍历每一列，如果在之前皇后的位置没有出现过，那么该位置放皇后
			if (judge(i, q)) {
				q.push_back(i);
				dfs(n, q);//递归
				q.pop_back();//回溯
			}
		}
	}

	int totalNQueens(int n) {
		vector<int> q;//存放每一行存放皇后的列的位置
		dfs(n, q);
		return cnt;
	}
};
int main() {
	int n = 4;
	Solution s;
	cout << s.totalNQueens(n) << endl;
}