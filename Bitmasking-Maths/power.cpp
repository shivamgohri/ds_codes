#include <iostream>

using namespace std;

int main(){

	int a, n;
	cin>> a >> n;

	//a^n

	int ans = 1;
	int atemp = a;

	while(n>0){

		int last_bit = n&1;

		if(last_bit == 1){
			ans = ans*atemp;
		}

		n = n>>1;
		atemp = atemp<<1;
	}

	cout<<ans<<endl;

	return 0;
}