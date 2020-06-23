#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


string lps(string x, string y){			//not working

	if(x.empty()){
		return "";
	}

	vector<vector<int> > dp( x.length()+1, vector<int> (y.length()+1, 0));

	int max_x = 0, max_y = 0;

	for(int i=1; i<=x.length(); i++){
		for(int j=1; j<=y.length(); j++){
			if(x[i-1]==y[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				if( dp[i][j] > dp[max_x][max_y] ){
					max_x = i;
					max_y = j;
				}
			}
			else{
				dp[i][j] = 0;
			}
		}
	}

	int i = max_x, j = max_y, n = dp[max_x][max_y], indx = dp[max_x][max_y]-1;

	string result(n, 'a');

	while(i>0 && j>0){

		if( x[i-1]==y[j-1] ){
			result[indx] = x[i-1];
			i--; j--; indx--;
		}
		else if( dp[i-1][j] > dp[i][j-1] ){
			i--;
		}
		else{
			j--;
		}
	}

	return result;
}


void testcases(){

	string s;
	cin>> s;
	string x = s;
	reverse(x.begin(), x.end());

	cout<< lps(s,x);
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