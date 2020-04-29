#include <iostream>

using namespace std;

int main(){

	long n = 1000000;

	long* arr = new long[n+1](); //0 - prime, 1 - not prime

	for(long i=3; i<=n; i++){
		if(i&1){
			if(arr[i]!=1){
				for(long j=i*i; j<=n; j=j+i){
					arr[j] = 1;
				}
			}
		}
		else{
			arr[i] = 1;
		}
	}

	long* csum = new long[n+1]();

	csum[2] = 1;
	for(long i=3; i<=n; i++){
		csum[i] = csum[i-1] + (arr[i]==1?0:1);
	}

	long t;
	cin>>t;
	while(t--){
		long a,b;
		cin>>a>>b;

		cout<< (csum[b] - csum[a-1]) <<endl;
	}

	return 0;
}