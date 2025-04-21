#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>
using namespace std;
int Method(vector<int>& nums,int k){
	int ans = INT_MAX;
	for(int i = 0;i < nums.size();i++){
		int n = 0;
		for(int j = i;j < nums.size();j++){
			n|=nums[j];
			if(n >= k){
				ans = min(ans,j-i+1);
				break;
			}
		}
	}
	return ans == INT_MAX?-1:ans;
}
int main(){
	vector<int> nums = {1, 2, 3};
        int k = 2;
		cout << Method(nums,k); 
}
