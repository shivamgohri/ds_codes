#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	int n;
	cin>> n;

	stack<string> s;
	string x;

	while(n--){

		cin>> x;

		if(s.empty()){
			s.push(x);
		}
		else{
			if(s.top()==x){
				s.pop();
			}
			else{
				s.push(x);
			}
		}
	}

	cout<< s.size();
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