#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back
#define mp make_pair
#define MAX (int)100


int dp[MAX][MAX];


int wines(int arr[], int i, int j, int y){

	if(i>j){
		return 0;
	}

	if(dp[i][j]!=0){
		return dp[i][j];
	}

	int op1 = (arr[i]*y) + wines(arr, i+1, j, y+1);
	int op2 = (arr[j]*y) + wines(arr, i, j-1, y+1);

	dp[i][j] = max(op1, op2);

	return dp[i][j];
}


int winesBU(int arr[], int n){


	for(int i=0; i<n; i++){

		int r = 0, c = i;

		while( r>=0 && r<n && c>=0 && c<n ){

			int year = (n - abs(c-r));

			int op1 = arr[r]*year + ( r+1>=n ? 0 : dp[r+1][c] );
			int op2 = arr[c]*year + ( c-1<0 ? 0 : dp[r][c-1] );

			dp[r][c] = max(op1, op2);

			r++;
			c++;
		}
	}

	return dp[0][n-1];
}



void testcases(){


	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	cout<< winesBU(arr, n);

}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}