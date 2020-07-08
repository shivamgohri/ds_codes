#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5
#define mod (int)1e9+7


void testcases(){

	string s, t;				//find t in s
	cin>> s >> t;

	vector<vector<int> > dp( t.length()+1, vector<int> (s.length()+1, 1));

	for(int i=1; i<=t.length(); i++){
		dp[i][0] = 0;
	}

	for(int i=1; i<=t.length(); i++){
		for(int j=1; j<=s.length(); j++){
			if(t[i-1]==s[j-1]){
				dp[i][j] = ( dp[i][j-1]%mod + dp[i-1][j-1]%mod )%mod;
			}
			else{
				dp[i][j] = dp[i][j-1]%mod;
			}
		}
	}

	cout<< dp[t.length()][s.length()];
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