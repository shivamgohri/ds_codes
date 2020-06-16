#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


bool canPartition(vector<int>& nums) {

	int sum = 0;

	for(int i=0; i<nums.size(); i++){
		sum += nums[i];
	}

	if( sum&1==1 ){
		return false;
	}

	sum = sum/2;

	bool dp[nums.size()+1][sum+1];

	dp[0][0] = true;

	for(int i=1; i<=sum; i++){
		dp[0][i] = false;
	}

	for(int i=1; i<=nums.size(); i++){
		dp[i][0] = true;    //because empty subset
	}

	for(int i=1; i<=nums.size(); i++){
		for(int j=1; j<=sum; j++){

			if( nums[i-1]<=j ){    			//include or exclude
				bool res = (dp[i-1][j]) || (dp[i-1][j-nums[i-1]]);
				dp[i][j] = res;
			}
			else{							//exclude
				dp[i][j] = dp[i-1][j];
			}

		}
	}

	return dp[nums.size()][sum];        
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