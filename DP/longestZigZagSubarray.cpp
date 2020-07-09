#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        
        if(A.empty()){
            return 0;
        }
        
        vector<vector<int> > dp(A.size(), vector<int> (2, 1));
        
        int ans = 1;
        
        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<2; j++){
                
                if(A[i-1]==A[i]){
                    dp[i][j] = 1;
                    continue;
                }
                
                if(j==0){
                    if( dp[i-1][j]&1 ){
                        if(A[i-1]<A[i]){
                            dp[i][j] = dp[i-1][j] + 1;
                            ans = max(ans, dp[i][j]);
                        }
                        else{
                            dp[i][j] = 1;
                        }
                    }
                    else{
                        if(A[i-1]>A[i]){
                            dp[i][j] = dp[i-1][j] + 1;
                            ans = max(ans, dp[i][j]);
                        }
                        else{
                            dp[i][j] = 2;
                        }
                    }
                }
                else{
                    if( dp[i-1][j]&1 ){
                        if(A[i-1]>A[i]){
                            dp[i][j] = dp[i-1][j] + 1;
                            ans = max(ans, dp[i][j]);
                        }
                        else{
                            dp[i][j] = 1;
                        }
                    }
                    else{
                        if(A[i-1]<A[i]){
                            dp[i][j] = dp[i-1][j] + 1;
                            ans = max(ans, dp[i][j]);
                        }
                        else{
                            dp[i][j] = 2;
                        }
                    }
                }                
            }
        }
        
        return ans;        
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