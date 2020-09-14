#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


bool compare(vector<int>& x, vector<int>& y){
	if(x[0]==y[0]) return x[1]>y[1];
	return x[0]>y[0];
}


void dfs(vector<vector<int> >& adj, vector<bool>& vis, vector<int>& req, int i, int& count, int& sum){

	vis[i] = true;
	count += 1;
	sum += req[i];

	for(int x=0; x<adj[i].size(); x++){
		int curr = adj[i][x];
		if(!vis[curr]){
			dfs(adj, vis, req, curr, count, sum);
		}
	}

	return;
}


void testcases(){

	int n, candies;
	cin>> n >> candies;

	vector<int> req(n, 0);

	for(int i=0; i<n; i++){
		cin>> req[i];
	}

	vector<vector<int> > adj(n);

	int p;
	cin>> p;

	int x, y;

	for(int i=0; i<p; i++){
		cin>> x >> y;
		adj[x-1].push_back(y-1);
	}

	vector<bool> vis(n, false);

	vector<vector<int> > res;

	int count, sum;

	for(int i=0; i<n; i++){
		if(!vis[i]){
			count = 0;
			sum = 0;
			dfs(adj, vis, req, i, count, sum);
			vector<int> temp(2, 0);
			temp[0] = sum;
			temp[1] = count;
			res.push_back(temp);
		}
	}

	sort(res.begin(), res.end(), compare);

	vector<vector<int> > dp(res.size()+1, vector<int> (candies+1, 0));

	int ans = 0;

	for(int i=1; i<=res.size(); i++){
		for(int j=1; j<=candies; j++){

			if( res[i-1][0]<=j ){
				dp[i][j] = max(dp[i][j], dp[i-1][j-res[i-1][0]] + res[i][1]);
				ans = max(ans, dp[i][j]);
			}

		}
	}

	cout<< ans;
	return;
}


int main(){

	// //compile
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}