#include <iostream>
#include <string>
#include <vector>

using namespace std;

void show(string s, string output, int i, int j, vector<vector<char> > arr){

	int digit = s[i]-'0';

	if(digit==1||digit==0){
		show(s, output, i+1, j, arr);
	}

	if(s[i]=='\0'){
		output[j] = '\0';
		cout<< output <<":"<<endl;
		return;
	}	

	for(int k=0; k<arr[s[i]-'0'].size(); k++ ){

		output[j] = arr[s[i]-'0'][k];
		show(s,output,i+1,j+1,arr);
	}

	return;
}

int main(){

	string s;
	cin>>s;

	vector<vector<char> > arr(9);

	arr[2].push_back('a');
	arr[2].push_back('b');
	arr[2].push_back('c');

	arr[3].push_back('d');
	arr[3].push_back('e');
	arr[3].push_back('f');

	string output(s.length(), ' ');
	show(s, output, 0, 0, arr);

	return 0;
}