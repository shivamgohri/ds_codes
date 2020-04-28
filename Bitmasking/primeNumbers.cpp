#include <iostream>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int* arr = new int[n+1](); //0 - prime, 1 - not prime, 2-2, 3-3

		arr[0] = arr[1] = 1;

		for(int i=2; i<=n; i++){

			if( arr[i]!=1 ){
				for(int j = i*i; j<=n; j+=i){
					arr[j] = 1;
				}
			}
		}

		for(int i=2; i<=n; i++){
			if(arr[i]==0){
				cout<< i <<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}