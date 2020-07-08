#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	string s1, s2, s3;
	cin>> s1 >> s2 >> s3;

	if( s1.empty() && s2.empty() ){
		if(s3.empty()){
			cout<< 1;
			return;
		}
		else{
			cout<< 0;
			return;
		}
	}

	if( s1.empty() && !s2.empty() ){
		cout<< (s2==s3)?1:0;
		return;
	}

	if( !s1.empty() && s2.empty() ){
		cout<< (s1==s3)?1:0;
		return;
	}

	vector<vector<bool> > dp( s1.length()+1, vector<bool> (s2.length()+1, false));

	dp[0][0] = true;

	for(int i=1; i<=s2.length(); i++){
		if(s2[i-1]==s3[i-1]){
			dp[0][i] = dp[0][i-1];
		}
	}

	for(int i=1; i<=s1.length(); i++){
		if(s1[i-1]==s3[i-1]){
			dp[i][0] = dp[i-1][0];
		}
	}

	for(int i=1; i<=s1.length(); i++){
		for(int j=1; j<=s2.length(); j++){

			if( s1[i-1]!=s3[i+j-1] && s2[j-1]!=s3[i+j-1] ){
				dp[i][j] = false;
			}
			else if( s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1] ){
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
			else if( s1[i-1]==s3[i+j-1] && s2[j-1]!=s3[i+j-1] ){
				dp[i][j] = dp[i-1][j];
			}
			else if( s1[i-1]!=s3[i+j-1] && s2[j-1]==s3[i+j-1] ){
				dp[i][j] = dp[i][j-1];
			}
			else{
				dp[i][j] = false;
			}
		}
	}

	cout<< dp[s1.length()][s2.length()];
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