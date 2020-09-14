#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007

int solve(vector<int>& happy, int indx, vector<int>& vis, vector<vector<int> >& dp){

	if(indx==happy.size()-1){
		for(int i=0; i<vis.size(); i++){
			if(vis[i]==false){
				return dp[i][indx] = happy[i] * abs(i-indx);
			}
		}
	}

	int ans = INT_MIN;
	for(int i=0; i<happy.size(); i++){
		if(vis[i]){
			continue;
		}
		vis[i] = true;
		if( dp[i][indx]!=-1 ){
			ans = max(ans, happy[i]*abs(i-indx) + dp[i][indx]);
		}
		else{
			int x = solve(happy, indx+1, vis, dp);
			dp[i][indx] = x;
			ans = max(ans, happy[i]*abs(i-indx) + x);
		}
		
		vis[i] = false;
	}

	return ans;
}


void testcases(){

	int n;
	cin>> n;

	vector<int> happy(n, 0);

	for(int i=0; i<n; i++){
		cin>> happy[i];
	}

	vector<int> vis(n, false);

	vector<vector<int> > dp(n, vector<int> (n, -1));

	cout<< solve(happy, 0, vis, dp);
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


// Virtual memory
// Thrashing
// Demand paging
// Belady's anamoly
// kernel
// DPKG Kinux Os