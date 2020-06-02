#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


string check(string str){

	stack<char> s;

	for(int i=0; i<str.length(); i++){

		char curr = str[i];

		if(curr=='('){
			s.push(curr);
		}
		else{
			if(s.empty()){
				return "Not Valid";
			}
			s.pop();
		}
	}

	if(s.empty()){
		return "Valid";
	}

	return "Not Valid";
}

void testcases(){

	string s;
	cin>> s;

	cout<< check(s) <<endl;
}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}