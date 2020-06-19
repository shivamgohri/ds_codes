#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int getMaxProfit(vector<int> weights, vector<int> prices, int rod){

	if( weights.empty() ){
		return 0;
	}

	vector<int> dp(rod+1, 0);

	for(int i=1; i<=weights.size(); i++){
		for(int j=1; j<=rod; j++){
			if( weights[i-1]<=j ){
				dp[j] = max( dp[j], dp[j-weights[i-1]]+prices[i-1]);
			}
		}
	}

	return dp[rod];
}


void testcases(){

	int n;
	cin>> n;

	vector<int> weights(n,0);
	vector<int> prices(n,0);

	for(int i=0; i<n; i++){
		cin>> weights[i];
	}

	for(int i=0; i<n; i++){
		cin>> prices[i];
	}

	cout<< getMaxProfit(weights, prices, n);
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