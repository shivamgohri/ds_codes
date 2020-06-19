#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int combinationSum4(vector<int>& nums, int target) {
	
	if(nums.empty()){
		if(target==0){
			return 1;
		}
		else{
			return 0;
		}
	}

	vector<double> dp(target+1, 0);
	dp[0] = 1;

	for(int i=1; i<=target; i++){
		for(int j=1; j<=nums.size(); j++){

			if( nums[j-1]<=i ){
				dp[i] += dp[i-nums[j-1]];
			}

		}
	}

	return dp[target];

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