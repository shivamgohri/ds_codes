#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	string s;
	cin>> s;

	stack<int> bracket;
	stack<int> star;

	for(int i=0; i<s.length(); i++){

		if(s[i]=='('){
			bracket.push(i);
		}
		else if(s[i]==')'){
			if(bracket.empty()){
				if(star.empty()){
					cout<< "Not valid";
					return;
				}
				else{
					star.pop();
				}
			}
			else{
				bracket.pop();
			}
		}
		else if(s[i]=='*'){
			star.push(i);
		}
	}

	if(bracket.empty()){
		cout<<"Valid";
		return;
	}
	else{

		while(!bracket.empty()){

			int b = bracket.top();
			bracket.pop();

			if(star.empty()){
				cout<< "Not valid";
				return;
			}
			else{
				if(b<star.top()){
					star.pop();
					continue;
				}
				else{
					cout<< "Not valid";
					return;
				}
			}
		}

		cout<<"Valid";
		return;
	}

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