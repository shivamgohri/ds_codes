#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e9+5

int solve(ull n, unordered_map<int, int> & dp){

	if(n>=INT_MAX){
		return -1;
	}

	if(n==1){
		return 0;
	}

	if( dp.find(n)!=dp.end() ){
		return dp[n];
	}

	if(n%6==0){
		int op1 =  solve(n/6, dp);
		if(op1==-1){
			return dp[n] = -1;
		}
		return dp[n] = op1+1;
	}
	else{
		int op1 =  solve(n*2, dp);
		if(op1==-1){
			return dp[n] = -1;
		}
		return dp[n] = op1+1;
	}
}


void testcases(){

	ull n;
	cin>> n;

	unordered_map<int, int> dp;

	cout<< solve(n, dp);
	return;
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