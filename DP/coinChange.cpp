#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int coinChange(vector<int>& coins, int amount) {
    
    if( coins.empty() ){
    	if(amount==0){
    		return 0;
    	}
    	else{
    		return -1;
    	}
    }

    int dp[coins.size()+1][amount+1]; 		//we can also use 1d dp array also, because current row in only important

    for(int i=1; i<=amount; i++){
    	dp[0][i] = INT_MAX - 1;
    }

    for(int i=0; i<=coins.size(); i++){
    	dp[i][0] = 0;
    }

    for(int i=1; i<=coins.size(); i++){
    	for(int j=1; j<=amount; j++){
    		if(coins[i-1]<=j){
    			dp[i][j] = min( dp[i-1][j], dp[i][j-coins[i-1]] + 1 );
    			if(dp[i][j]==INT_MAX){
    				dp[i][j] = INT_MAX - 1;
    			}
    		}
    		else{
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }

    if(dp[coins.size()][amount]==INT_MAX-1){
    	return -1;
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