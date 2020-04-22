#include <iostream>

using namespace std;

int last_occurence(int* arr, int k, int left, int right){

	int ans = -1;

	while(left<=right){

		int mid = (left+right)/2;

		if(arr[mid]==k){
			ans = mid;
			left = mid+1;
		}
		else if( k>arr[mid] ){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}

	return ans;

}

int first_occurence(int* arr, int k, int left, int right){

	int ans = -1;

	while(left<=right){

		int mid = (left+right)/2;

		if(arr[mid]==k){
			ans = mid;
			right = mid-1;
		}
		else if( k>arr[mid] ){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}

	return ans;

}

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int k;
	cin>>k;

	cout<< first_occurence(arr,k,0,n-1) <<endl;
	cout<< last_occurence(arr,k,0,n-1) <<endl;

}