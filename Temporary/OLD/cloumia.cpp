#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007

int solve(int& n, int& cost, int& m, int prev, int i, int c){

	if(i==n){
		if(c==cost){
			return 1;
		}
		else{
			return 0;
		}
	}

	if(c==cost){
		return pow((prev-1),(n-i));
	}

	int ans = 0;
	for(int x=prev; x>=1; x--){
		int t = solve(n, cost, m, x, i+1, c);
		ans += t;
	}

	for(int x=prev+1; x<=(m); x++){
		int t = solve(n, cost, m, x, i+1, c+1);
		ans += t;
	}

	return ans;
}


vector<int> arrayCount(vector<int> n, vector<int> m, vector<int> cost){

	vector<int> ans(n.size(), 0);

	for(int i=0; i<n.size(); i++){
		int x = 0;
		for(int prev=1; prev<=m[i]-cost[i]; prev++){
			int t = solve(n[i], cost[i], m[i], prev, 1, 0);
			x += t;
		}
		ans[i] = x;
	}

	return ans;
}


void testcases(){

	int a;
	cin>> a;

	vector<int> n(a);
	vector<int> m(a);
	vector<int> cost(a);

	for(int i=0; i<a; i++){
		cin>> n[i];
	}

	for(int i=0; i<a; i++){
		cin>> m[i];
	}

	for(int i=0; i<a; i++){
		cin>> cost[i];
	}

	vector<int> ans = arrayCount(n, m, cost);

	for(int i=0; i<ans.size(); i++){
		cout<< ans[i] <<" ";
	}

	return;
}


int main(){

	//compile
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}