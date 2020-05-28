#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define max (int)1e7+5


int coins[3] = {1, 7, 10};

int dp[max];


int coinChange(int n){

	if(n==0){
		return 0;
	}

	if(dp[n]!=0){
		return dp[n];
	}

	int m = INT_MAX;

	for(int i=0; i<3; i++){
		if( n-coins[i] >= 0 ){
			m = min( m, coinChange(n - coins[i]) );
		}
	}

	return dp[n] = m+1;
}


int BU(int n){

	for(int i=1; i<=n; i++){

		int m = INT_MAX;

		for(int j=0; j<3; j++){
			if( i - coins[j] >= 0 ){
				m = min(m, dp[i-coins[j]] );
			}
		}
		dp[i] = m+1;
	}

	return dp[n];
}


void testcases(){

	int n;
	cin>> n;

	cout<< BU(n);

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