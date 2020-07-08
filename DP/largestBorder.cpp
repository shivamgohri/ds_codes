#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


void testcases(){
    
    int n;
    cin>> n;
    
    vector<vector<char> > arr(n, vector<char> (n, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> arr[i][j];
        }
    }
    
    int left[n][n];
    int up[n][n];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]=='X'){
                left[i][j] = (j==0) ? 1 : left[i][j-1]+1;
                up[i][j] = (i==0) ? 1 : up[i-1][j]+1;
            }
            else{
                left[i][j] = up[i][j] = 0;
            }
        }
    }
    
    int ans = 0;
    
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            
            int x = min(left[i][j], up[i][j]);
            
            while(x>ans){
                if( left[i-x+1][j]>=x && up[i][j-x+1]>=x ){
                    ans = x;
                }
                x--;
            }
        }
    }
    
    cout<< ans;
    return;
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}







