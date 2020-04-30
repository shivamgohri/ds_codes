//https://practice.geeksforgeeks.org/problems/shreyansh-and-his-bits/0

#include <iostream>

using namespace std;

#define ll unsigned long long int

ll c(ll n, ll r){

	cout<<n<<","<<r<<endl;

	if(n<r) {return 0;}

	ll val = 1L;
	// ll numerator = 1L;
	// ll denomenator = 1L;

	ll diff = n-r;
    for(int i=1; i<=diff; i++)
    {
        val=(n-i+1)*val/i;
        cout<<i<<","<<val<<endl;
    }

	// while(r!=0){

	// 	if( numerator%denomenator == 0 ){
	// 		val *= numerator/denomenator;
	// 		numerator = 1L;
	// 		denomenator = 1L;
	// 	}

	// 	numerator *= n;
	// 	denomenator *= r;
	// 	n--;
	// 	r--;		
	// }

	// val *= numerator/denomenator;
	return val;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		ll n;
		cin>>n;

		ll count = 0L;
		ll position = 0L;
		ll result = 0L;

		int loop = 64;
		while(loop--){

			if(n&1==1){

				count++;

				if(position!=0)
					result = result + c(position, count);
			}

			n = n>>1;
			position++;
		}

		cout<<result<<endl;
	}

	return 0;
}