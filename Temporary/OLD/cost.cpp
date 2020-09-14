#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


ull solve(vector<int>& arr, int i, vector<int>& vis, vector<ull>& dp){

	if(dp[i]!=-2){
		return dp[i];
	}

	vis[i] = true;

	ull op1 = INT_MAX, op2 = INT_MAX;

	if( (i+2)>=arr.size() ){
		return (ull)arr[i];
	}
	else{
		op1 = solve(arr, i+2, vis, dp);
	}

	if( !vis[i-1] && (i-1)>=0 ){
		op2 = solve(arr, i-1, vis, dp);
	}

	return (ull) ( min(op1, op2) + (ull) arr[i] );
}


void testcases(){
	
	int n;
	cin>> n;

	vector<int> arr(n, 0);

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	vector<int> vis(n, false);
	vector<ull> dp(n, -2);
	cout<< solve(arr, 0, vis, dp);
	return;
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