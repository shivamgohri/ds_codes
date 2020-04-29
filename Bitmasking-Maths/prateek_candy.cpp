#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(){

	ll t;
	cin>>t;

	ll n = 1000000ll;

	vector<ll> arr(n+1,0); //0-prime, 1 - not prime

	arr[0] = arr[1] = 1;

	for(ll i=3; i<=n; i++){

		if(i&1){
			if(arr[i]==0){
				for(ll j=i*i; j<=n; j=j+i){
					arr[j] = 1;
				}
			}
		}
		else{
			arr[i] = 1;
		}
	}

	vector<ll> sum;

	for(ll i=0; i<n; i++){
		if(arr[i]==0){
			sum.push_back(i);
		}
	}

	while(t--){

		ll x;
		cin>>x;

		cout<<sum[x-1]<<endl;
	}

	return 0;
}