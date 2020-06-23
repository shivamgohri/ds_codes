#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int solve(vector<vector<int> >& dp, int arr[], int i, int j){
	if(i>=j){
		return 0;
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	int m = INT_MAX;
	for(int k=i; k<j; k++){
		int count = solve(dp, arr, i, k) + solve(dp, arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
		m = min(m, count);
	}

	return dp[i][j] = m;
}


void testcases(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	vector<vector<int> > dp(n+5, vector<int> (n+5, -1));

	cout<< solve(dp, arr, 1, n-1);
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