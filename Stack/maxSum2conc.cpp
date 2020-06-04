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

	ull* arr = new ull[n]();

	stack<ull> s;
	ull ans = 0, x;

	for(int i=0; i<n; i++){

		if(i<2){
			cin>> x;
			s.push(x);
			ans += x;
		}
		else{
			cin>> x;
			if(x+s.top()>ans){
				ans = x + s.top();
			}
			s.push(x);
		}

	}

	cout<< ans;
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