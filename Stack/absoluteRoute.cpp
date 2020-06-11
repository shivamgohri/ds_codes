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

	stack<string> s;

	for(int i=0; i<str.length(); i++){

		while(str[i]=='/'){
			i++;
		}

		string name = "";

		while( i<str.length() && str[i]!='/' ){
			name += str[i];
			i++;
		}

		if( name==".." ){
			if(!s.empty()){
				s.pop();
			}
		}
		else if(name=="."){
			continue;
		}
		else{
			s.push(name);
		}
	}

	string result = "";

	while(!s.empty()){
		if(result.empty()){
			result = s.top();
		}
		else{
			result = s.top() + "/" + result;
		}
		s.pop();
	}
	result = "/" + result;

	cout<< result;
	return;
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