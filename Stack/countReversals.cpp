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

	int ans = 0;

	for(int i=0; i<str.length(); i++){

		if( str[i]=='}' ){

			if(s.empty()){
				ans += 1;
				s.push('{');
			}
			else{
				s.pop();
			}

		}
		else if( str[i]=='{' ){
			s.push('{');
		}
	}

	if( s.size()&1 ){
		cout<< -1;
	}
	else{
		ans += s.size()/2;
		cout<< ans;
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