#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){
    
    int a, b;
    cin>> a >> b;

	string x, y;
	cin>> x >> y;

	vector<vector<int> > dp( x.length()+1, vector<int> (y.length()+1, 0));

	dp[0][0] = 0;

	for(int i=1; i<=x.length(); i++){
		dp[i][0] = i;
	}

	for(int i=1; i<=y.length(); i++){
		dp[0][i] = i;
	}

	for(int i=1; i<=x.length(); i++){
		for(int j=1; j<=y.length(); j++){

			if(x[i-1]==y[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min( dp[i][j-1], min( dp[i-1][j], dp[i-1][j-1]));
			}
		}
	}
	
	for(int i=0; i<dp.size(); i++){
	    for(int j=0; j<dp[i].size(); j++){
	        cout<< dp[i][j] <<" ";
	    }
	    cout<<endl;
	}

	cout<< dp[x.length()][y.length()];
	return;
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