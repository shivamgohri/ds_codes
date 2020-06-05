//https://practice.geeksforgeeks.org/problems/save-gotham/0
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX (int)1e7+5


void testcases(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	stack<int> s;
	ull ans = 0;

	for(int i=n-1; i>=0; i--){

		if(s.empty()){
			s.push(arr[i]);
			ans = ans%mod;
			continue;
		}

		if( s.top()>arr[i] ){
			ans = ( s.top()%mod + ans%mod )%mod;
			s.push(arr[i]);
		}
		else{
			while( s.top()<=arr[i] ){ 				// = is important as only greater number is required
				s.pop();
				if(s.empty()){
					break;
				}
			}
			if(!s.empty()){
				ans = ( s.top()%mod + ans%mod )%mod;
			}
			s.push(arr[i]);
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