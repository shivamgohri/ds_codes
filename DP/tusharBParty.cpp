#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    if(A.empty() || B.empty() || (B.size()!=C.size()) ){
        return 0;
    }
    
    int maxCap = INT_MIN;    
    
    for(int i=0; i<A.size(); i++){
        maxCap = max(maxCap, A[i]);
    }
    
    vector<vector<int> > dp( B.size()+1, vector<int> (maxCap+1, 0));
    
    for(int i=1; i<=maxCap; i++){
        dp[0][i] = INT_MAX;
    }
    
    int ans = 0;
    
    for(int i=1; i<=B.size(); i++){
        for(int j=1; j<=maxCap; j++){
            
            if( B[i-1]<=j ){
                if( dp[i][j-B[i-1]]==INT_MAX ){
                    if( dp[i-1][j]==INT_MAX ){
                        dp[i][j] = INT_MAX;
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else{
                    if( dp[i-1][j]==INT_MAX ){
                        dp[i][j] = dp[i][j-B[i-1]] + C[i-1];
                    }
                    else{
                        dp[i][j] = min( dp[i-1][j], dp[i][j-B[i-1]] + C[i-1]);
                    }
                }
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for(int i=0; i<A.size(); i++){
        ans += dp[B.size()][A[i]];
    }
    
    return ans;
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