//https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0

#include <iostream>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;


bool check( int arr[], int n, int a, int mid ){

	int sum = 0;
	int count = 1;

	for(int i=0; i<n; i++){

		if(arr[i]>mid){
			return false;
		}

		if( sum+arr[i] > mid ){
			count++;
			sum = arr[i];

			if(count>a){
				return false;
			}
		}
		else{
			sum += arr[i];
		}
	}

	return true;
}


int main(){

	int t;
	cin>>t;

	while(t--){

		int a, n;
		cin>>a>>n;

		int* arr = new int[n]();

		for(int i=0; i<n; i++)
			cin>>arr[i];

		if(a<=n){
			cout<< *max_element(arr, arr+n) <<endl;
		}
		else{

			int s = *max_element(arr, arr+n);
			int e = accumulate(arr, arr+n, 0);

			int ans = INT_MAX;

			while(s<=e){

				int mid = (s+e)/2;

				bool isPossible = check( arr, n, a, mid );

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
	}

	return 0;
}