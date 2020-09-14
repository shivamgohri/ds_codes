#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


void testcases(){

	ull n;
	cin>> n;

	ull start = 0, end = n;
	ull ans = 0;
	ull mid;

	while(start<end){

		mid = (start + (end-start)/2);

		ull curr = (mid) * (mid+1) * (mid+2)/6;

		if(curr==n){
			ull ans = mid*(mid+1)/2;
			cout<< ans;
			return;
		}
		else if(mid<n){
			start = mid+1;
			ans = mid;
		}
		else{
			end = mid-1;
		}
	}

	ull prev = (ans-1)*(ans)*(ans+1)/6;
	n = n - prev;

	ull prevans = 

	return;

}


int main(){

	//compile
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}