#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int A) {
    
    int startrow = 0, endrow = A-1, startcol = 0, endcol = A-1;
    
    vector<vector<int> > ans(A, vector<int> (A,0));
    int a=1;
    while( startrow<=endrow && startcol<=endcol ){
        
        for(int i=startcol; i<=endcol; i++){
            ans[startrow][i] = a;
            a++;
        }
        startrow++;
        
        for(int i=startrow; i<=endrow; i++){
            ans[i][endcol] = a;
            a++;
        }
        endcol--;
        
        
        if(endrow>startrow){
            for(int i=endcol; i>=startcol; i--){
                ans[endrow][i] = a;
                a++;
            }
            endrow--;
        }
        
        if(endcol>startcol){
            for(int i=endrow; i>=startrow; i--){
                ans[i][startcol] = a;
                a++;
            }
            startcol++;
        }
    }
    
    
    
    return ans;
}

int main(){

	int n;
	cin>> n;

	vector<vector<int> > result = generateMatrix(n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<< result[i][j] <<" ";
		}
		cout<< endl;
	}

	return 0;
}