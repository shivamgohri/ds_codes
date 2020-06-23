#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int minimumTotal(vector<vector<int>>& triangle) {
        
    if(triangle.empty()){
        return 0;
    }
    
    for(int i=triangle.size()-2; i>=0; i--){
        for(int j=0; j<triangle[i].size(); j++){
            
            int m = min( triangle[i+1][j] , triangle[i+1][j+1]);
            triangle[i][j] += m;
            
        }
    }
    
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