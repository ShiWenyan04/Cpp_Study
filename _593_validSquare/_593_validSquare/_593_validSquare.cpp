#include <iostream>
#include <vector>


/*给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。
点的坐标 pi 表示为 [xi, yi] 。 输入没有任何顺序 。
一个 有效的正方形 有四条等边和四个等角(90度角)。
示例 1:
输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
输出: true
示例 2:
输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
输出：false
示例 3:
输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
输出：true*/
using namespace std;

class Solution {
public:
	bool isRightTriangle(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
		//三角形的三条边，利用两点之间距离公式求得，因为后面还要平方，所以没有用sqrt
		int a = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
		int b = pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2);
		int c = pow(p3[0] - p2[0], 2) + pow(p3[1] - p2[1], 2);
		 
		//判断是否是等边直角三角形
		if ((a  + b  == c && a == b && a != 0) 
			||( a  + c  == b  && a == c && a != 0)
			||( c  + b == a&&c == b && a != 0)) {
			return true;
		}
		return false;
	}
	//任意取三个点，判断构成的三角形是否都是等边直角三角形
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		return isRightTriangle(p1, p2, p3) && isRightTriangle(p4, p2, p3) && isRightTriangle(p1, p4, p3) && isRightTriangle(p1, p2, p4);
	}
};
int main() {
	vector <int> p1 = { 0, 0 }, p2 = { 1, 1 }, p3 = { 1, 0 }, p4 = { 0, 1 };
	Solution s;
	cout << s.validSquare(p1, p2, p3, p4) << endl;
	return 0;
}