/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int Solution::minimumTotal(vector<vector<int> >& triangle) {
    
    //Base case
    if(triangle.empty()){
        return 0;
    }
    
    //Start iterating from second-last row, and find the maximum
    //from its children and store the current answer on the left
    for(int i=triangle.size()-2; i>=0; i--){
        for(int j=0; j<triangle[i].size(); j++){
            
            int m = min( triangle[i+1][j] , triangle[i+1][j+1]);
            triangle[i][j] += m;
            
        }
    }
    
    //Answer will be at the top position
    return triangle[0][0]; 
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