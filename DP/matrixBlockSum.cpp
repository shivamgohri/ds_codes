#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

class Solution {
public:
    int min(int a, int b){
        return (a<b)?a:b;
    }
    
    int max(int a, int b){
        return (a<b)?b:a;
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        if(mat.empty()){
            return mat;
        }
        
        vector<vector<int>> sum(mat.size(), vector<int> (mat[0].size(), 0));
        vector<vector<int>> ans(mat.size(), vector<int> (mat[0].size(), 0));
        
        sum[0][0] = mat[0][0];
        for(int i=1; i<mat.size(); i++){
            sum[i][0] = sum[i-1][0] + mat[i][0];
        }
        for(int i=1; i<mat[0].size(); i++){
            sum[0][i] = sum[0][i-1] + mat[0][i];
        }
        
        for(int i=1; i<mat.size(); i++){
            for(int j=1; j<mat[0].size(); j++){
                sum[i][j] = sum[i][j-1] + sum[i-1][j] + mat[i][j] - sum[i-1][j-1];
            }
        }
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                int x = max(0, i-K), y = max(0, j-K);
                int a = min(mat.size()-1, i+K), b = min(mat[i].size()-1, j+K);   
                int add = 0;
                if( x-1>=0 && y-1>=0 ){
                    add = sum[x-1][y-1];
                }
                ans[i][j] = sum[a][b] + add - (x-1<0?0:sum[x-1][b]) - (y-1<0?0:sum[a][y-1]);       
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