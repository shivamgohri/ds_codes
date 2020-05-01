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

int main(){

	int n;
	cin>>n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	bubbleSort(arr, 0, n-1);

	for(int i=0; i<n; i++){
		cout<< arr[i] <<" ";
	}
	cout<<endl;

	return 0;
}