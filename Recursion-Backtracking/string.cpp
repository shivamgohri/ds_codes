#include <iostream>
#include <vector>
#include <string>

using namespace std;

void subsequences(string s, string output, int i, int j){

	if(s[i]=='\0'){
		output[j] = '\0';
		cout<< output <<":" <<endl;
		return;
	}

	output[j] = s[i];
	subsequences(s,output,i+1,j+1);

	subsequences(s,output,i+1,j);

	return;
}

void permutation(string s, int left, int right){

	if(left==right){
		cout<<s<<endl;
		return;
	}
	else{

		for(int i=left; i<=right; i++){
			swap(s[i], s[left]);
			permutation(s, left+1, right);
			swap(s[i], s[left]);
		}
	}

	return;
}

int main(){

	string s;
	cin>>s;

	string output(s.length(), ' ');

	permutation(s,0,s.length()-1);
	cout<< "----" <<endl;
	subsequences(s, output, 0, 0);

	return 0;
}