#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int key){

	if(left>right){
		return -1;
	}

	int mid = (left+right)/2;

	if(arr[mid]==key){
		return mid;
	}
	else if(arr[mid]<key){
		left = mid+1;
		return binarySearch(arr, left, right, key);
	}
	else{
		right = mid - 1;
		return binarySearch(arr, left, right, key);
	}
}

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	int key;
	cin>> key;

	cout<< binarySearch(arr, 0, n-1, key);

	return 0;
}