#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007



void testcases(){

	string A, B;
	cin>> A >> B;
	
	B += B;

	int m = 2*B.length();
	int n = A.length();
	
	int helper = 0;
	int position = 0, length = 0;
	int count[m + 1];

	count[1] = 0;

	for (int i = 2; i <= n; i++) {
	  
		while (helper > 0 && A[helper] != A[i - 1])
			helper = count[helper];

		if (A[helper] == A[i - 1])
			++helper;
			count[i] = helper;
		}

		for (int j = 0, i = 0; i < m; i++) {
			while (j > 0 && A[j] != B[i])
				j = count[j];
			if (A[j] == B[i])
				j++;
			if (j > length) {
				length = j;
				position = i - j + 1;
			}
	}

	if( length == 0 ){
		cout<< -1;
	}
	else{
		cout<< length;
	}

}


int main(){

	//compile
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}