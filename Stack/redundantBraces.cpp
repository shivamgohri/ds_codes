#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	string str;
	cin>> str;

	stack<char> s;

	for(int i=0; i<str.length(); i++){

		char ch = str[i];

		if(ch=='('){
			s.push(ch);
		}
		else if(ch==')'){
			bool valid = false;

			while( !s.empty() && s.top()!='(' ){
				char x = s.top();
				s.pop();
				if( x=='+' || x=='*' || x=='/' || x=='-' ){
					valid = true;
				}
			}

			if(!valid){
				cout<< 1;
				return;
			}
			else{
				s.pop();
			}
		}
		else{
			s.push(ch);
		}
	}

	cout<< 0;
	return;
}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}