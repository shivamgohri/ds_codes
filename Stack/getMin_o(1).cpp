#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	// 1 x - push(x)
	// 0 - pop
	// 2 - geMitn
	// -1 - stop

	int n;
	cin>> n;

	stack<int> s;
	int minVal = INT_MAX;

	while(n!=-1){

		if(n==1){
			int x;
			cin>> x;

			if( x >= minVal ){
				s.push(x);
			}
			else{
				s.push( (2*x) - minVal );
				minVal = x;
			}

		}
		else if( n==0 ){
			int x = s.top();
			s.pop();

			if( x <= minVal ){
				minVal = (2*minVal) - x;
			}
		}
		else if(n==2){
			cout<< minVal <<endl;
		}

		cin>> n;
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