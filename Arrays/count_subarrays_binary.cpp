#include <iostream>
#include <vector>

using namespace std;

int main(){

	int t;
	cin>> t;

	while(t--){

		int n, temp, count = 0;
		cin>> n;

		long int ans = 0;
		vector<int> arr(2*n +1, 0);

		arr[n] = 1;
		for(int i=0; i<n; i++){
			
			cin>> temp; 
			count += (temp==0?-1:1) ;

			if( arr[count+n] > 0 ){
			    ans += arr[n+count];
			    arr[count+n]++;
			}
			else{
			    arr[count+n]++;
			}

		}

		cout<< ans <<endl;

	}

	return 0;
}