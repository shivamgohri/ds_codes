//count the minimum steps to one 
//n => (n/3) or (n/2) or (n-1)

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define max (int)1e7+5

int dp[max];

int minSteps(int n){

	if(n==1){
		return 0;
	}

	if(dp[n]!=0){
		return dp[n];
	}

	int op1, op2, op3;
	op1 = op2 = op3 = INT_MAX;

	if(n%3==0){
		op1 = minSteps(n/3) + 1;
	}
	if(n%2==0){
		op2 = minSteps(n/2) + 1;
	}
	op3 = minSteps(n-1) + 1;

	int ans = min(min(op1, op2), op3);

	return dp[n] = ans;
}


int minBU(int n){

	dp[1] = 0;

	for(int i=2; i<=n; i++){

		int op1, op2, op3;

		op1 = op2 = op3 = INT_MAX;

		if( i%3==0 ){
			op1 = dp[i/3];
		}
		if( i%2==0 ){
			op2 = dp[i/2];
		}
		op3 = dp[i-1];

		dp[i] = min(min(op1, op2), op3) + 1;
	}

	return dp[n];
}


void testcases(){

	int n;
	cin>> n;

	cout<< minBU(n);

}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}