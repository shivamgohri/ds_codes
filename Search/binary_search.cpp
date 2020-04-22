#include <iostream>

using namespace std;

int binary_search(int* arr, int k, int left, int right){

	while(left<=right){

		int mid = (left+right)/2;

		if(arr[mid]==k){
			return mid;
		}
		else if( k>arr[mid] ){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}

	return -1;

}

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int k;
	cin>>k;

	cout<< binary_search(arr,k,0,n-1) <<endl;

}