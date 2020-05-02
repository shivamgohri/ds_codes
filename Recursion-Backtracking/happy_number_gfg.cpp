//https://practice.geeksforgeeks.org/problems/next-happy-number/0

#include <iostream>
#include <vector>

using namespace std;

bool isHappy(int n, vector<int> v){

	if(n==1){
		return true;
	}

	for(int i=0; i<v.size(); i++){
		if(v[i]==n){
			v.clear();
			return false;
		}
	}

	v.push_back(n);

	int temp = 0;

	while(n>0){
		int last_digit = n%10;
		temp += (last_digit*last_digit);
		n = n/10;
	}

	return isHappy(temp, v);
}

int nextHappyNumber(int n){

	n++;
	vector<int> v;
	while( isHappy(n, v)!=true ){
		n++;
	}

	return n;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		cout<< nextHappyNumber(n) <<endl;
	}	

	return 0;
}