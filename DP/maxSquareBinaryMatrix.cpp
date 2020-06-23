#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	int n, m;
	cin>> n >> m;

	vector<vector<int> > mat(n, vector<int> (m,0));

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>> mat[i][j];
		}
	}

	vector<vector<int> > dp(n+1, vector<int> (m+1,0));
	
	int ans = 0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(mat[i-1][j-1]==0){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = 1 + min(dp[i-1][j], min( dp[i-1][j-1], dp[i][j-1]));
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout<< ans;
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