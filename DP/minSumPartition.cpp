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

	int* arr = new int[n]();

	int total = 0;	

	for(int i=0; i<n; i++){
		cin>> arr[i];
		total += arr[i];
	}

	if(n==1){
		cout<< arr[0];
		return;
	}

	int sum = total/2;

	bool dp[n+1][sum+1];

	for(int i=0; i<=n; i++){
		dp[i][0] = true;
	}

	for(int i=1; i<=sum; i++){
		dp[0][i] = false;
	}

	int m = 0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			if(arr[i-1]<=j){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
				if(dp[i][j]){
					m = max(m, j);
				}
			}
			else{
			    dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout<< total-(2*m);
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