#include <iostream>
#include <algorithm>

using namespace std;


bool can_place( int arr[], int n, int c, int min_sep){

	int count = 1;
	int last_cow = arr[0];

	for(int i=1; i<n; i++){

		if( arr[i]-last_cow >= min_sep ){

			last_cow = arr[i];
			count++;

			if(count == c){
				return true;
			}
		}
	}

	return false;
}


int main(){


	int t;
	cin>> t;

	while(t--){

		int stalls, cows;
		cin>>stalls>>cows;

		int* arr = new int[stalls]();

		for(int i=0; i<stalls; i++){
			cin>> arr[i];
		}

		sort(arr, arr+stalls);

		int s = 0;
		int e = arr[stalls-1] - arr[0];

		int ans = 0;

		while(s<=e){

			int mid = (s+e)/2;

			bool check = can_place( arr, stalls, cows, mid);

			if(check){
				ans = mid;
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}

		cout<< ans <<endl;
	}

	return 0;
}