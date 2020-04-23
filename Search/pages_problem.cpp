#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;


bool can_allot(int arr[], int n, int a, int min){

	int students = 1;
	long int curr_sum = 0;

	for(int i=0; i<n; i++){

		if(arr[i]>min){
			return false;
		}

		if( curr_sum + arr[i] > min ){
			students++;
			curr_sum = arr[i];

			if(students>a){
				return false;
			}
		}
		else{
			curr_sum += arr[i];
		}
	}

	return true;
}



int main(){


	int t;
	cin>>t;
	while(t--){


		int n;
		cin>> n;

		int* arr = new int[n]();

		for(int i=0; i<n; i++)
			cin>> arr[i];

		int a;
		cin>>a;

		if( a>n ){
			cout<< -1 <<endl;
		}

		else{

			int s = *max_element(arr, arr+n);
			int e = accumulate(arr, arr+n, 0);

			long int ans = INT_MAX;

			while(s<=e){

				long int mid = (s+e)/2;

				bool check = can_allot( arr, n, a, mid );

				if(check){
					ans = min(ans,mid);
					e = mid-1;
				}
				else{
					s = mid+1;
				}
			}

			cout<< ans <<endl;

		}
	}


	return 0;
}