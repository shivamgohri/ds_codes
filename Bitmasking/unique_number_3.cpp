#include <iostream>

using namespace std;

int main(){

	int n, no;
	cin>>n;

	int* arr = new int[64]();

	while(n--){

		cin>>no;

		int j=0;
		while(no>0){
			int last_bit = no&1;
			arr[j] += last_bit;
			j++;
			no = no>>1;
		}
	}

	int ans = 0, p = 1;

	for(int i=0; i<64; i++){
		arr[i] = arr[i]%3;
		ans += (arr[i]*p);
		p = p*2;
	}

	cout<<ans<<endl;

	return 0;
}