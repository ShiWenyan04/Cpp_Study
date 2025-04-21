#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int Method(string word,int k){
	int n = word.size();
	unordered_map<string,int> hashmap;
	int res = INT_MAX;
	for(int i = 0;i < n;i+=k){
		string part = word.substr(i,k);
		hashmap[part]++;
		res = min(res,n/k-hashmap[part]);
	} 
	return res;
}
int main(){
	string word = "leetcodeleet";
	int k = 4;
	cout<<Method(word,k);
}
