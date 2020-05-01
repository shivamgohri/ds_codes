#include <iostream>

using namespace std;

#define ll unsigned long long

ll mul(int a, int b){

	ll prod = b;
	prod = prod << 32;

	int t = 32;
	while(t--){

		ll temp = 1L;
		temp = temp<<63;

		ll s = (prod&temp);

		if( s == temp ){
			prod = prod << 1;
			prod = (ll)prod + a;
		}
		else{
			prod = prod << 1;
		}
	}

	return prod;
}

int main(){

	int a, b;
	cin>> a >> b;

	cout<< mul(a,b) <<endl;

}