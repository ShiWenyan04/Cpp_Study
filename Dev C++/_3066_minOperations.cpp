#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int Method(vector<int>& nums,int k){
	int count = 0 ;
	priority_queue<long long,vector<long long>,greater<long long>> queue(nums.begin(),nums.end()); 
	while(queue.top() < k){
		long long x = queue.top();queue.pop();
		long long y = queue.top();queue.pop();
		queue.push(x*2+y);
		count++;
	}
	return count;
}
int main(){
	vector<int> nums = {2, 11, 10, 1, 3};
    int k = 10;
    cout << Method(nums,k);
}
