#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	int n, w;
	cin>> n >> w;

	int* values = new int[n]();
	int* weights = new int[n]();

	for(int i=0; i<n; i++){
		cin>> values[i];
	}

	for(int i=0; i<n; i++){
		cin>> weights[i];
	}

	int dp[w+1] = {0};

	for(int i=1; i<=n; i++){
		for(int j=w; j>=1; j--){
			if(weights[i-1]<=j){
				dp[j] = max( dp[j], values[i-1] + dp[j-weights[i-1]]);
			}
			else{
				dp[j] = dp[j];
			}
		}
	}

	cout<< dp[w];
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