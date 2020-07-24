#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.empty()){
            return 0;
        }
        
        queue<pair<int, int> > q;
        
        int zeroCount = 0;
        int freshCount = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push( make_pair(i, j) );
                }
                if(grid[i][j] == 1){
                    freshCount++;
                }
                if(grid[i][j] == 0){
                    zeroCount++;
                }
            }
        }
        
        if(zeroCount == grid.size()*grid[0].size() ){
            return 0;
        }
        
        int ans = -1;
        
        while(!q.empty()){
            
            int n = q.size();
            ans++;
            
            while(n--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if( j-1>=0 && grid[i][j-1]==1 ){
                    grid[i][j-1] = 2;
                    q.push( make_pair(i, j-1) );
                    freshCount--;
                }
                
                if( j+1<grid[i].size() && grid[i][j+1]==1 ){
                    grid[i][j+1] = 2;
                    q.push( make_pair(i, j+1) );
                    freshCount--;
                }
                
                if( i-1>=0 && grid[i-1][j]==1 ){
                    grid[i-1][j] = 2;
                    q.push( make_pair(i-1, j) );
                    freshCount--;
                }
                
                if( i+1<grid.size() && grid[i+1][j]==1 ){
                    grid[i+1][j] = 2;
                    q.push( make_pair(i+1, j) );
                    freshCount--;
                }                
            }
        }
        
        if(freshCount!=0){
            return -1;
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
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}