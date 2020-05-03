//https://practice.geeksforgeeks.org/problems/permutation-with-spaces/0

#include <iostream>
#include <string>

using namespace std;

void permutation(string input, string output, int i){

	if(i==input.length()){
		cout<<'('<< output <<')';
		return;
	}

	permutation(input, (output+" "+input[i]), i+1);
	permutation(input, (output+input[i]), i+1);
	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		string input;
		cin>>input;

		string output = "";
		output = output + input[0];

		permutation( input, output, 1);
		cout<<endl;
	}

	return 0;
}