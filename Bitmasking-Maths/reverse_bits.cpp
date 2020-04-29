#include <iostream>

using namespace std;

int main(){

	long long n;
	cin>>n;

	int* arr = new int[32]();

	long long pos = 0;
	while(n>0){
		arr[pos] = (n&1);
		n = n>>1;
		pos++;
	}

	long long ans = 0, p = 1;

	for(int i=31; i>=0; i--){

		ans += arr[i]*p;
		p = p*2;
	}

	cout<<ans<<endl;

	return 0;
}