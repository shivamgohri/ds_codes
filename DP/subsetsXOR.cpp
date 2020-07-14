#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int solve(vector<int>& arr, int k){

	int n = arr.size();

	if(n==0){
		return 0;
	}

	int max_ele = *max_element(arr.begin(), arr.end());
	int m = (1 << (int)(log2(max_ele) + 1) ) - 1;

	if(k>m){
		return 0;
	}

	vector<vector<int> > dp(n+1, vector<int> (m+1, 0));

	dp[0][0] = 1;

	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];
		}
	}

	return dp[n][k];
}


void testcases(){

	int n, k;
	cin>> n >> k;

	vector<int> arr(n, 0);

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	cout<< solve(arr, k);
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