#include <iostream>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int* arr = new int[n]();

		for(int i=0; i<n; i++)
			cin>>arr[i];

		long ans = 0;

		for(int i=0; i<32; i++){
			
			long cz = 0, co = 0;

			for(int j=0; j<n; j++){

				if(arr[j]&1 == 1){
					co++;
				}
				else{
					cz++;
				}

				arr[j] = arr[j]>>1;
			}

			ans += (cz*co)*(1<<i);
		}

		cout<<ans<<endl;
	}

	return 0;
}