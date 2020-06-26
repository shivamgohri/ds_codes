#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

class Solution {
public:
    bool solve(vector<int>& piles, int i, int j, int a, int b, bool turn, vector<vector<vector<int>>>& dp){
        if(i>j){
            return a>=b;
        }
        
        if( dp[i][j][ (turn)?1:0 ]!=-1 ){
            return dp[i][j][ (turn)?1:0 ];
        }
        
        if(turn){
            return dp[i][j][1] = solve(piles, i+1, j, a+piles[i], b, !turn, dp) || solve(piles, i, j-1, a+piles[j], b, !turn, dp);
        }
        else{
            return dp[i][j][1] = solve(piles, i+1, j, a, b+piles[i], !turn, dp) || solve(piles, i, j-1, a, b+piles[j], !turn, dp);
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        if(piles.empty()){
            return true;
        }
        int n = piles.size();
        vector<vector<vector<int>>> dp( n, vector<vector<int>> (n, vector<int> (2, -1)));
        return solve(piles, 0, piles.size()-1, 0, 0, true, dp);
    }
};




void testcases(){



}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}