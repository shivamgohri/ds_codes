//https://www.spoj.com/problems/PRATA/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


bool check( int arr[], int n, int p, int mid ){

	int count = 0;	

	for(int i=0; i<n; i++){

		int j = 1;
		long int time = 0;
		while(1){

			time += j*arr[i];
			j++;

			if(time>mid)
				break;

			count++;	
		}
	}

	if(count>=p){
		return true;
	}

	return false;
}



int main(){

	int t;
	cin>>t;
	while(t--){

		int p;
		cin>>p;

		int n;
		cin>>n;

		int* arr = new int[n]();

		for(int i=0; i<n; i++)
			cin>>arr[i];

		int s = 0;
		long int e = (*max_element(arr, arr+n))*(p*(p+1)/2);

		int ans = INT_MAX;

		while(s<=e){

			int mid = (s+e)/2;

			bool isPossible = check( arr, n, p, mid );

			if(isPossible){

				ans = min(ans, mid);
				e = mid-1;

			}
			else{
				s = mid+1;
			}
		}

		cout<< ans <<endl;
	}

	return 0;
}