/*
Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix.
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:

1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000
Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    
    //Base case
    if(B.empty()){
        vector<vector<int> > ans;
        return ans;
    }
    
    // Maintain 2 arrays
    vector<vector<int> > curr = B;
    vector<vector<int> > next = curr;

    //Every-time look for max in Manhattan distance of 1, and decrease it    
    while(A-->0){
        
        //Find max element in 1 - Manhattan distance
        for(int i=0; i<B.size(); i++){
            for(int j=0; j<B[0].size(); j++){

            	//Left, right, up, down & current element are the only
            	//options for 1 - Manhattan distance                
                int l = (j-1>=0) ? curr[i][j-1] : INT_MIN;
                int r = (j+1<B[0].size()) ? curr[i][j+1] : INT_MIN;
                int u = (i-1>=0) ? curr[i-1][j] : INT_MIN;
                int d = (i+1<B.size()) ? curr[i+1][j] : INT_MIN;
                
                next[i][j] = max( max(l, max(r, u)), max(d, curr[i][j]));
            }
        }
        
        //Update current as ans
        curr = next;
    }
    
    return curr;
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