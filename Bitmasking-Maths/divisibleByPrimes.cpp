//https://hack.codingblocks.com/app/practice/5/1264/problem

#include <iostream>
using namespace std;

#define ll long long

int main(){

	ll t;
	cin>>t;

	while(t--){

		ll n;
		cin>>n;

		ll m;
		cin>>m;

		ll* arr = new ll[m]();

		for(ll i=0; i<m; i++)
			cin>>arr[i];

		ll subSets = (1<<m);
		ll ans = 0ll;

		for(ll i = 1; i<subSets; i++){

			ll denom = 1;
			ll setBits = __builtin_popcount(i);

			ll j = 0, temp = i;

			while(temp>0){
				int last_bit = temp&1;
				if(last_bit==1){
					denom = denom*arr[j];
				}
				j++;
				temp = temp>>1;
			}

			if(setBits&1){
				ans += n/denom;
			}
			else{
				ans -= n/denom;
			}

		}

		cout<< ans <<endl;
	}

	return 0;
}