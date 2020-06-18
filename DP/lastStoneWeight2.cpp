#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

int lastStoneWeightII(vector<int>& stones) {
	
	if(stones.empty()){
		return 0;
	}

	if(stones.size()==1){
		return stones[0]; 
	}

	int total = accumulate(stones.begin(), stones.end(), 0);

	int sum = total/2;

	bool dp[stones.size()+1][sum+1];

	dp[0][0] = true;

	for(int i=1; i<=sum; i++){
		dp[0][i] = false;
	}

	for(int i=1; i<=stones.size(); i++){
		dp[i][0] = true;
	}

	int m = 0;

	for(int i=1; i<=stones.size(); i++){
		for(int j=1; j<=sum; j++){
			if(stones[i-1]<=j){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
				if(dp[i][j]){
					m = max(m, j);
				}
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return total - (2*m);
}


void testcases(){



}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}