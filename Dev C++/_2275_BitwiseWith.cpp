#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Method(int num[]){
	int len = 0;
	for(int i = 0;i < 24;i++){
		int preLen = 0;
		for(int j = 0; j < sizeof(num) ;j++ ){
			if((num[j] & (1<<i) )!=0){
				preLen ++;
			}
		}
		len = max(len,preLen);
	}
	return len;
}
int main(){
	int num [] = {16, 17, 71, 62, 12, 24, 14};
	cout << Method(num)<<endl;
} 
