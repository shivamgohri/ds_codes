#include <iostream>

using namespace std;

#define ll long long

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int* arr = new int[n]();

		arr[0] = 1;

		ll sum = 0;

		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			sum += x;
			sum = ((sum%n)+n)%n;
			arr[sum]++;
		}

		ll ans = 0;

		for(int i=0; i<n; i++){
			ll m = arr[i];
			ans += (m)*(m-1)/2;
		}

		cout<<ans<<endl;
	}

	return 0;
}
