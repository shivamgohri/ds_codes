#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int solve(vector<vector<int> >& dp, int e, int f){

	if( f==0 || f==1 ){
		return f;
	}

	if(e==1){
		return f;
	}

	if(dp[e][f]!=-1){
		return dp[e][f];
	}

	int ans = INT_MAX;

	for(int k=1; k<=f; k++){
		int n = 1 + max( solve(dp, e-1, k-1), solve(dp,e,f-k));
		ans = min(ans, n);
	}

	return dp[e][f] = ans;
}

int solvedp(int e, int f){

	vector<vector<int> > dp(e+1, vector<int> (f+1, 0));

	for(int i=0; i<=e; i++){
		dp[i][1] = 1;
	}

	for(int i=0; i<=f; i++){
		dp[1][i] = i;
	}

	for(int i=2; i<=e; i++){
		for(int j=2; j<=f; j++){
			dp[i][j] = INT_MAX;
			for(int x=1; x<=j; x++){
				int res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
				dp[i][j] = min(res, dp[i][j]);
			}
		}
	}

	return dp[e][f];
}


void testcases(){

	int e, f;
	cin>> e >> f;

	vector<vector<int> > dp(e+1, vector<int> (f+1, -1));

	cout<< solvedp(e,f);
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