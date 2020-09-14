#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


void testcases(){
	
	int n;
	cin>> n;

	vector<int> arr1(n, 0);
	vector<int> arr2(n, 0);

	for(int i=0; i<n; i++){
		cin>> arr1[i];
	}

	for(int i=0; i<n; i++){
		cin>> arr2[i];
	}

	unordered_map<int, int> m;

	for(int i=0; i<n; i++){
		m[arr1[i]] = i;
	}

	int count = 0;
	for(int i=0; i<n-2; i++){

		int curr = m[arr2[i]];
		int s = i+1, e = n-1;

		while(s<e){

			if(m[arr2[s]] < curr){
				s++;
			}
			else if( m[arr2[e]] < curr ){
				e--;
			}
			else{
				count++;
				s++;
				e--;
			}
		}	
	}

	cout<< count;
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}