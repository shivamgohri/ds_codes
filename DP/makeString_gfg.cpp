//https://practice.geeksforgeeks.org/problems/minimal-moves-to-form-a-string/0
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	string s;
	cin>> s;

	vector<int> dp(s.length(), INT_MAX);

	dp[0] = 1;
	string res = "";
	res += s[0];
	string temp = "";

	for(int i=1; i<s.length(); i++){

		res += s[i];

		dp[i] = min( dp[i], dp[i-1]+1 );

		if( (s.length()-i-1)>=(i+1) ){
		    temp = s.substr(i+1, i+1);
		    if( res==temp ){
		        dp[(i*2)+1] = min( dp[(i*2)+1], dp[i]+1);
		    }
		}
	}

	cout<< dp[s.length()-1];
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