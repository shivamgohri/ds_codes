//https://www.interviewbit.com/problems/prettyprint/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > prettyPrint(int A) {
    
    int n = 1 + (A-1)*2;
    
    vector<vector<int> > ans(n, vector<int> (n,0));
    
    int m = A;
    
    int srow = 0, erow = n-1, scol = 0, ecol = n-1;

    while( srow<=erow && scol<=ecol ){

    	for(int i=scol; i<=ecol; i++){
    		ans[srow][i] = m;
    	}
    	srow++;

    	for(int i=srow; i<= erow; i++){
    		ans[i][ecol] = m;
    	}
    	ecol--;

    	if( srow<erow ){
    		for(int i=ecol; i>=scol; i--){
    			ans[erow][i] = m;
    		}
    		erow--;
    	}

    	if( scol<ecol ){
    		for(int i=erow; i>=srow; i--){
    			ans[i][scol] = m;
    		}
    		scol++;
    	}

    	m--;
    }
	
	return ans;      
}

int main(){

	int A;
	cin>>A;

	vector<vector<int> > result = prettyPrint(A);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result.size(); j++){
			cout<< result[i][j] <<" ";
		}
		cout<<endl;
	}

	return 0;
}