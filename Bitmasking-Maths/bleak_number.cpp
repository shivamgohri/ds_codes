//https://practice.geeksforgeeks.org/problems/bleak-numbers/0

#include <iostream>

using namespace std;

int ceil(int n){
	int count = 0;
	n--;
	while(n>0){
		count++;
		n = n>>1;
	}

	return count;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n, flag = 0;
		cin>>n;

		for(int i= (n-ceil(n)); i<n; i++ ){
			if( i + __builtin_popcount(i) == n ){
				flag = 1;
				break;
			}
		}

		if(flag==0){
			cout<<1<<endl;
		}
		else{
		    cout<<0<<endl;
		}
	}

	return 0;
}