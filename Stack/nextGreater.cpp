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

	for(int i=0; i<n; i++)
		cin>> arr[i];

	ll* ans = new ll[n]();

	stack<ull> s;

	for(int i=n-1; i>=0; i--){

		if(s.empty()){
			ans[i] = -1;
			s.push(arr[i]);
			continue;
		}

		if( s.top()<=arr[i] ){

			while( s.top()<=arr[i] ){
				s.pop();
				if(s.empty()){
					break;
				}
			}

			if(s.empty()){
				ans[i] = -1;
				s.push(arr[i]);
				continue;
			}
			else{
				ans[i] = s.top();
				s.push(arr[i]);
			}
		}
		else{
			ans[i] = s.top();
			s.push(arr[i]);
		}
	}

	for(int i=0; i<n; i++){
		cout<< ans[i] <<" ";
	}
	return;
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