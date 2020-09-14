#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


int dfs(unordered_map<int, pair<int, vector<int> > >& m, vector<bool>& vis, int src, int& ans){

	vis[src] = true;

	vector<int> arr;
	int curr = m[src].first;

	for(auto v:m[src].second){
		if(!vis[v]){
			arr.push_back(dfs(m, vis, v, ans));
		}
	}

	if(arr.empty()){
		return curr;
	}

	int t = max(curr, curr + *max_element(arr.begin(), arr.end()));
	int x = max( accumulate(arr.begin(), arr.end(), 0)+curr, t);
	ans = max(ans, x);

	vis[src] = false;
	return t;
}


void testcases(){

	int n;
	cin>> n;

	unordered_map<int, pair<int, vector<int> > > m;

	int x;
	for(int i=1; i<=n; i++){
		cin>> x;
		m[i].first = x;
	}

	int y;
	for(int i=0; i<n-1; i++){
		cin>> x >> y;
		m[x].second.push_back(y);
		m[y].second.push_back(x);
	}

	vector<bool> vis(n+1, false);

	int ans = INT_MIN;
	dfs(m, vis, 1, ans);

	cout<< ans;	
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