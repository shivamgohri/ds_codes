#include <bits/stdc++.h>

using namespace std;

typedef long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	string str;
	cin>> str;

	stack<ull> s;

	for(int i=0; i<str.length(); i++){

		if( str[i]=='+' ){
			ull x = s.top();
			s.pop();
			ull y = s.top();
			s.pop();
			s.push(y+x);
		}
		else if(str[i]=='-'){
			ull x = s.top();
			s.pop();
			ull y = s.top();
			s.pop();
			s.push(y-x);
		}
		else if(str[i]=='*'){
			ull x = s.top();
			s.pop();
			ull y = s.top();
			s.pop();
			s.push(y*x);
		}
		else if(str[i]=='/'){
			ull x = s.top();
			s.pop();
			ull y = s.top();
			s.pop();
			s.push(y/x);
		}
		else{
			s.push(str[i] - '0');
		}
	}

	cout<< s.top();

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