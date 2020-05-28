#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back
#define max (int)1e7+5


int dp[max];


int fibonacciTD(int n){

	if(n==1 || n==0){
		return n;
	}

	if(dp[n]!=0){
		return dp[n];
	}

	int a = fibonacciTD(n-1);
	int b = fibonacciTD(n-2);
	int c = a + b;

	return dp[n] = c;
}


int fibonacciBU(int n){

	dp[1] = 1;

	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}


void testcases(){

	int n;
	cin>> n;

	cout<< fibonacciBU(n);

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