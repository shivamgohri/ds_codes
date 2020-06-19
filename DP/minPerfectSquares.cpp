#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int numSquares(int n) {

	int x = sqrt(n) + 1;

	vector<int> dp( x+1, vector<int> (n+1, 0) );

	for(int i=1; i<=n; i++){
		dp[0][i] = INT_MAX - 1;
	}

	for(int i=1; i<=x; i++){
		for(int j=1; j<=n; j++){

			long long int curr = (i);
			curr = curr*curr;

			if( curr <= (long long int)j ){
				dp[i][j] = min( dp[i-1][j], dp[i][j-curr] + 1);
				if(dp[i][j]==INT_MAX){
					dp[i][j] = INT_MAX - 1;
				}
			}
			else{
				dp[i][j] = dp[i-1][j];
			}

		}
	}

	return dp[x][n];
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