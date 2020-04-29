#include <iostream>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		long n;
		cin>>n;

		long temp = n;
		int pos = 0;

		while(temp>0){
			pos++;
			temp = temp>>1;
		}

		n = n - (1<<pos-1);

		n = n<<1;
		n++;
		cout<<n<<endl;

	}

}