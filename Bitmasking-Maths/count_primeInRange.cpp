#include <iostream>

using namespace std;
#define ll unsigned long long

int main(){

	ll n = 1000000ll;

	ll* arr = new ll[n+1](); //0 - prime, 1 - not prime

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

	ll* csum = new ll[n+1]();

	ll ans = 0ll;

	for(ll i=0; i<=n; i++){
		csum[i] = ans;

		if(arr[i]==0){
			ans++;
		}		
	}

	ll t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;

		cout<< (csum[b+1] - csum[a]) <<endl;
	}

	return 0;
}