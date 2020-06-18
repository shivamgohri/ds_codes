#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	int n;
	cin>> n;

	vector<int> v(n,0);

	int total = 0;

	for(int i=0; i<n; i++){
		cin>> v[i];
		total += v[i];
	}

	if( n==1 && v[0]==0 ){
		cout<< "YES";
		return;
	}

	if(total&1){
		cout<< "NO";
		return;
	}

	int sum = total/2;

	bool dp[v.size()+1][sum+1];

	dp[0][0] = true;

	for(int i=1; i<=v.size(); i++){
		dp[i][0] = true;
	}

	for(int i=1; i<=sum; i++){
		dp[0][i] = false;
	}

	for(int i=1; i<=v.size(); i++){
		for(int j=1; j<=sum; j++){

			if( v[i-1]<=j ){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}

		}
	}

	if(dp[v.size()][sum]){
		cout<< "YES";
	}
	else{
		cout<< "NO";
	}

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