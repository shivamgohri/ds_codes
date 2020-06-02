#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void transfer1(stack<int>& s1, stack<int>& s2, int n){
	while(n--){
		s2.push(s1.top());
		s1.pop();
	}
}


void testcases(){

	stack<int> s1;

	for(int i=1; i<=5; i++){
		s1.push(i);
	}

	int n = s1.size();
	stack<int> s2;

	for(int i=0; i<n; i++){

		int x = s1.top();
		s1.pop();

		transfer1(s1, s2, n-i-1);
		s1.push(x);
		transfer1(s2, s1, n-i-1);
	}

	while(!s1.empty()){
		cout<< s1.top() <<endl;
		s1.pop();
	}

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