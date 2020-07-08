#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	string s, p;
	cin>> s >> p;

	vector<vector<bool> > dp( s.length()+1, vector<bool> (p.length()+1, false));

	dp[0][0] = true;

	for(int i=1; i<=p.length(); i++){
		if(p[i-1]=='*'){
			dp[0][i] = dp[0][i-1];
		}
	}

	for(int i=1; i<=s.length(); i++){
		for(int j=1; j<=p.length(); j++){
			if(s[i-1]==p[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else if(p[j-1]=='?'){
				dp[i][j] = dp[i-1][j-1];
			}
			else if(p[j-1]=='*'){
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
			else{
				dp[i][j] = false;
			}
		}
	}

	cout<< dp[s.length()][p.length()];
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