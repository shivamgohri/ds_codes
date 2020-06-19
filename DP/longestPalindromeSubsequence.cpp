#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int lps(string s){

	
    if(s.empty()){
        return 0;
    }

	string x = s;
	string y = s;
	reverse(y.begin(), y.end());

	vector<vector<int> > dp( x.length()+1, vector<int> (y.length()+1, 0));

	for(int i=1; i<=x.length(); i++){
		for(int j=1; j<=y.length(); j++){

			if( x[i-1]==y[j-1] ){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[x.length()][y.length()];

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