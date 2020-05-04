//https://practice.geeksforgeeks.org/problems/power-of-numbers/0

#include <iostream>

using namespace std;

#define ll unsigned long long
#define mod 1000000007

ll power(ll number, ll reverse){

	ll ans = 1L;

	while(reverse>0){

		int last_digit = reverse&1;

		if(last_digit==1){
			ans = ans*( number );
			ans = ans % mod;
		}

		number = number * number;
		number = number % mod;

		reverse = reverse>>1;
	}

	ans  = ans % mod;

	return ans;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		ll number;
		cin>>number;

		ll reverse = 0L;
		ll temp = number;

		while(temp>0){
			int last_digit = temp % 10;
			reverse = (reverse*10) + (last_digit);
			temp = temp/10;
		}

		// cout<<number<<","<<reverse<<endl;

		cout<< power(number, reverse) <<endl;
	}

	return 0;
}