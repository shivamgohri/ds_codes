#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

int findTargetSumWays(vector<int>& nums, int S) {        
    
	if(nums.size()==1){
        if(nums[0]==S || nums[0]==-S || -nums[0]==S){
            return 1;
        }
        else{
            return 0;
        }
    }

    int sum = 0;
    int zeros = 0;

    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(nums[i]==0){
            zeros++;
        }
    }

    if( sum<S || ( (sum+S)%2==1 ) ){
        return 0;
    }

    int temp = (sum+S)/2;

    vector<vector<int> > dp( nums.size()+1, vector<int> ( temp+1, 0 ) );

    for(int i=0; i<=nums.size(); i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<=nums.size(); i++){
        for(int j=1; j<=temp; j++){
            if(nums[i-1]==0){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            if( nums[i-1]<=j ){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    // for(int i=0; i<=nums.size(); i++){
    //     for(int j=0; j<=temp; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<< endl;
    // }

    return dp[nums.size()][temp] * pow(2, zeros);       
  
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