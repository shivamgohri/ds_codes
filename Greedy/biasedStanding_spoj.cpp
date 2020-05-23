#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back


void testcases(){

	int n;
	cin>> n;

	int* arr = new int[n+1]();

	for(int i=0; i<n; i++){
		string s;
		cin>> s;
		int x;
		cin>> x;
		arr[x]++;
	}

	ll ans = 0;
	int currRank = 1;

	for(int i=0; i<=n; i++){
		if( arr[i]!=0 ){
			
			while(arr[i]>0){
				ans += abs(currRank-i);
				currRank++;
				arr[i]--;
			}

		}
	}

	cout<<ans;

}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}

// 1 2 3 4 5 6 7
// 2 2 0 0 1 0 2

// 