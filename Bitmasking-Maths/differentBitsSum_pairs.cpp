//https://practice.geeksforgeeks.org/problems/find-sum-of-different-corresponding-bits-for-all-pairs/0
//HARD

#include <iostream>

using namespace std;

#define mod 1000000007
#define ll long long

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		ll* arr = new ll[n]();

		for(int i=0; i<n; i++)
			cin>>arr[i];

		ll ans = 0;
		for(int i=0; i<32; i++){

			ll co = 0, cz = 0;

			for(int i=0; i<n; i++){

				if(arr[i]&1==1){
					co++;
				}
				else{
					cz++;
				}

				arr[i] = arr[i]>>1;
			}

			ans += (cz*co);
		}

		ans = ans*2;

		cout<< ans%mod <<endl;
	}

	return 0;
}