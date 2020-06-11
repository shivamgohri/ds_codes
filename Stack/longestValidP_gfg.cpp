//https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0
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
	stack<int> n;

	for(int i=0; i<str.length(); i++){

		if( str[i]=='(' ){
			s.push('(');
			n.push(1);
		}
		else if( str[i]==')' ){
			if(!s.empty()){
				s.pop();
				
				int num = 0;
				while( !n.empty() && n.top()!=1 ){
					num += n.top();
					n.pop();
				}

				if( n.empty() ){
					n.push(num);
					continue;
				}

				if( !n.empty() && n.top()==1 ){
					n.pop();
					num += 2;
					n.push(num);
				}
			}
			else{
				n.push(1);
			}
		}
	}

	int ans = 0, temp = 0;

	while( !n.empty() ){

		int x = n.top();
		n.pop();

		if(x==1){
			temp = 0;
		}
		else{
			temp += x;
			ans = max(ans, temp);
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