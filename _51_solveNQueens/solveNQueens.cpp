#include<iostream>
#include<vector>
#include <string>
#include <cmath>
/*按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。*/
using namespace std;
/*思路：
1.使用idx数组存放第i行皇后所在的位置，idx数组的索引表示行
2.由于放置位置要行、列、斜对角线均不相同，所以要判断当前位置是否在之前的出现过
3.由于要找出所有的方案，所以要采用dfs*/

vector<vector<string>> list;// 用于存储最终的所有解法

//判断
bool judge(int i, vector<int>& q) {
	int row = q.size();
	if (row == 0) {//如果是第一个皇后，随便放都可以
		return true;
	}
	for (int k = 0; k < row; k++) {//否则判断前面的皇后是否和当前的同列或同对角线
		if (q[k] == i) {//同列
			return false;
		}else if ( abs(q[k] - i) == abs(row - k) ) {//同对角线
			return false;
		}
	}
	return true;
}

//棋盘打印
vector<string> board(vector<int>q,int n) {
	vector<string> b;
	for (int i = 0; i < n; i++) {//枚举行
		string row(n, '.');//初始化每行为“."
		int idx = q[i];//当前行皇后存放的位置
		row[idx] = 'Q';
		b.push_back(row);//行存入棋盘
	}
	return b;
}

//递归
void dfs(int n,vector<int>& q) {
	if (q.size() == n) {//如果放置了n个皇后，表示找到了一种解法
		list.push_back(board(q, n));//棋盘
		return;
	}
	
	for (int i = 0; i < n; i++) {//当前行遍历每一列，判断之前的皇后是否与之同列
		if (judge(i, q)) {
			q.push_back(i);//放置皇后
			dfs(n, q);//dfs
			q.pop_back();//回溯
		}
	}
}

class Solution {
public :
	vector<vector<string>> solveNQueens(int n){
		list.clear();
		vector<int> q;//存放皇后每一行的位置
		dfs(n,q);
		return list;
	}
};

int main() {
	int n = 4;
	Solution s;
	s.solveNQueens(n);
	//打印所有解法
	for (auto& board : list) {
		for (auto& row : board) {
			cout << row << endl;//换行
		}
		cout << endl;
	}
}