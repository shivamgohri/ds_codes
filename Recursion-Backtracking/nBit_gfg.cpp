//https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s/0

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void permutations(string s, vector<string>& result, int ones, int zeros, int n){

	if(zeros>ones) {return;}

	if(s.length()==n){
		result.push_back(s);
		return;
	}

	permutations( (s+"1"), result, ones+1, zeros, n);
	permutations( (s+"0"), result, ones, zeros+1, n);

	return;
}

int main() {

	int t;
	cin>> t;

	while(t--){

		int n;
		cin>>n;

		string s = "1";
		vector<string> result;

		permutations(s, result, 1, 0, n);

		for(int i=0; i<result.size(); i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;

	}

	return 0;
}