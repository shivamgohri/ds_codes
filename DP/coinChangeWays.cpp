#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int change(int amount, vector<int>& coins) {

	if(coins.empty()){
		if(amount==0){
			return 1;
		}
		else{
			return 0;
		}
	}

	int dp[coins.size()+1][amount+1];

	for(int i=0; i<=coins.size(); i++){
		dp[i][0] = 1;
	}

	for(int i=1; i<=amount; i++){
		dp[0][i] = 0;
	}

	for(int i=1; i<=coins.size(); i++){
		for(int j=1; j<=amount; j++){
			if(coins[i-1]<=j){
				dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[coins.size()][amount];

}


void testcases(){



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