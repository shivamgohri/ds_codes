#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define ip(arr) for(int i=0; i<arr.size(); i++) cin>>arr[i];
#define ip1(arr) for(int i=1; i<=arr.size(); i++) cin>>arr[i];
#define op(arr) for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";

#define MAX 10000000
#define mod 100000007


void testcases(){

	int c,d,r,p;
	cin>> c >> d >> r >> p;

	int s = 0, e = c;

	int ans = 0;

	while(s<=e){

		int mid = s + (e-s)/2;

		ull sell = c - mid, left = mid;
		sell = sell*r;
		left = left*p;

		if( left == (sell + d) ){
			ans = mid;
			cout<< ans;
			return;
		}
		else if( left < (sell+d) ){
			ans = max(ans, mid);
			s = mid+1;
		}
		else{
			e = mid-1;
		}

	}

	cout<< ans;

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