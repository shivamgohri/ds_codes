#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void insertAtBottom(stack<int>&s, int x){
	if(s.empty()){
		s.push(x);
		return;
	}

	int y = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(y);

	return;
}

void reverse(stack<int>& s){
	if(s.empty()){
		return;
	}

	int x = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s, x);

	return;
}

void testcases(){
	stack<int> s1;

	for(int i=1; i<=5; i++){
		s1.push(i);
	}

	reverse(s1);

	while(!s1.empty()){
		cout<< s1.top() <<endl;
		s1.pop();
	}
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