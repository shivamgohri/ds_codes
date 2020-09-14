#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define ip(x) for(int i=0; i<x.size(); i++) cin>>x[i];
#define ip1(x) for(int i=1; i<=x.size(); i++) cin>>x[i];
#define op(x) for(int i=0; i<x.size(); i++) cout<<x[i]<<" ";

#define MAX 10000000
#define mod 100000007


void testcases(){

	int n;
	cin>> n;

	vector<ull> arr(n, 0);	
	ip(arr);	

	sort(arr.begin(), arr.end());

	ull cost = 0;
	ull c = 0;

	for(int i=1; i<=sqrt(arr[2]); i++){
		if( i*i<=arr[2] ){
			c = i;
		}
	}

	for(int i=0; i<n; i++){
		ull t = abs(pow(c,i) - arr[i]);
		cost += t;
	}

	cout<< cost;
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