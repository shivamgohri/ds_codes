#include <iostream>
#include <string>
#include <vector>

using namespace std;

void show(string s, string output, int i, int j, vector<vector<char> > arr, vector<string>& result){

	int digit = s[i]-'0';

	if(digit==1||digit==0){
		show(s, output, i+1, j, arr, result);
	}

	if(s[i]=='\0'){
		output[j] = '\0';
		result.push_back(output);
		return;
	}	

	for(int k=0; k<arr[s[i]-'0'].size(); k++ ){

		output[j] = arr[s[i]-'0'][k];
		show(s,output,i+1,j+1,arr, result);
	}

	return;
}

int main(){

	string s;
	cin>>s;

	vector<vector<char> > arr(10);

	arr[0].push_back('0');
	arr[1].push_back('1');	

	arr[2].push_back('a');
	arr[2].push_back('b');
	arr[2].push_back('c');

	arr[3].push_back('d');
	arr[3].push_back('e');
	arr[3].push_back('f');

	arr[4].push_back('g');
	arr[4].push_back('h');
	arr[4].push_back('i');

	arr[5].push_back('j');
	arr[5].push_back('k');
	arr[5].push_back('l');

	arr[6].push_back('m');
	arr[6].push_back('n');
	arr[6].push_back('o');

	arr[7].push_back('p');
	arr[7].push_back('q');
	arr[7].push_back('r');
	arr[7].push_back('s');

	arr[8].push_back('t');
	arr[8].push_back('u');
	arr[8].push_back('v');

	arr[9].push_back('w');
	arr[9].push_back('x');
	arr[9].push_back('y');
	arr[9].push_back('z');

	vector<string> result;

	string output(s.length(), ' ');
	show(s, output, 0, 0, arr, result);

	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<endl;
	}

	return 0;
}