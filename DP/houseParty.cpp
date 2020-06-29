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

	vector<int> dp(n+1, 0);

	dp[0] = dp[1] = 1;

	for(ll i=2; i<=n; i++){
		dp[i] = ( dp[i-1] + (i-1)*dp[i-2] )%1000000007;
	}

	cout<< dp[n];
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