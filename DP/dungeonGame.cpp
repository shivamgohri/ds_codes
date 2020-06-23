#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

class Solution {
public:
    
    int solve(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>>& dp){
        
        if( i==dungeon.size() || j==dungeon[0].size() ){
            return INT_MAX;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int r, d;
        r = d = INT_MAX;
        
        if( i+1<dungeon.size() ){
            d = solve(dungeon, i+1, j, dp);
        }
        
        if( j+1<dungeon[i].size() ){
            r = solve(dungeon, i, j+1, dp);
        }
        
        int m = min(r,d);
        if(m==INT_MAX){
            m = 1;
        }
        
        return dp[i][j] = max( m-dungeon[i][j], 1);        
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()){
            return 0;
        }
        
        vector<vector<int> > dp( dungeon.size(), vector<int> (dungeon[0].size(), -1));
        
        int res = solve(dungeon, 0, 0, dp);
        return res;
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