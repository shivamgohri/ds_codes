#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

class Solution {
public:
    
    int solve(int n, vector<int>& dp){
        
        if(n==0 || n==1){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += solve(i-1, dp)*solve(n-i, dp);
        }
        
        return dp[n] = ans;        
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};


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