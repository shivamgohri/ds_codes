#include <iostream>

using namespace std;

void bubbleSort(int arr[], int left, int right){

	if(left==right){return;}

	for(int i=0; i<right; i++){
		if(arr[i]>arr[i+1]){
			swap(arr[i], arr[i+1]);
		}
	}

	bubbleSort(arr, left, right-1);
	return;
}

void bubbleSort1(int arr[], int j, int n){

	if(n==1){return;}

	if(j==n-1){
		bubbleSort1(arr, 0, n-1);
		return;
	}

	if(arr[j]>arr[j+1]){
		swap(arr[j], arr[j+1]);
	}

	bubbleSort1(arr, j+1, n);
	return;
}

int main(){

	int n;
	cin>>n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	bubbleSort1(arr, 0, n);

	for(int i=0; i<n; i++){
		cout<< arr[i] <<" ";
	}
	cout<<endl;

	return 0;
}