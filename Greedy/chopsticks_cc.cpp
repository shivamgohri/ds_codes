#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back


void testcases(){

	ll n, d;
	cin>> n>> d;

	ll* arr = new ll[n]();

	for(ll i=0; i<n; i++)
		cin>> arr[i];

	sort(arr, arr+n);

	ll ans = 0;

	for(int i=0; i<n-1; i++){
		if( arr[i]+d>=arr[i+1] ){
			ans++;
			i++;
		}
	}

	cout<< ans;
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
	}

	return 0;
}