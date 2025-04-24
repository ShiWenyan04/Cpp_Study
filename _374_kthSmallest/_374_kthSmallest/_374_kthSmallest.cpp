#include <iostream>
#include <vector>

/*给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。
你必须找到一个内存复杂度优于 O(n2) 的解决方案。
示例 1：
输入：matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
输出：13
解释：矩阵中的元素为 [1,5,9,10,11,12,13,13,15]，第 8 小元素是 13
示例 2：
输入：matrix = [[-5]], k = 1
输出：-5*/
using namespace std;


class Solution {
public:
    bool  check(vector<vector<int>>& matrix,int mid, int k,int n) {
        int i = n-1, j = 0;//从右下角开始遍历
        int sum = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {//对角线式遍历      设martrix[i][j]为x
                sum+=i+1;//因为是排序好 的二维矩阵，所以左上角板块小于右下角板块，当x小于mid时，这一列在x上面的 均小于mid，所以为i+1
                j++;//从前往后
            }else{
                i--;//从下往上
            }
        }
        return sum >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];//左上角的值
        int right = matrix[n - 1][n - 1];//右下角的值
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(matrix, mid, k, n)) {//小于mid的个数大于等于k，说明第k小的值在mid左边
                right = mid;
            }else{
                left = mid+1;//大于mid 的个数小于k，说明mid太小了

            }
        };
        return left;
    }
};

int main(){
   vector<vector<int>>matrix = { {1, 5, 9},{10, 11, 13},{12, 13, 15} };
   int k = 8;
   Solution s;
   cout << s.kthSmallest(matrix, k) << endl;
    
}