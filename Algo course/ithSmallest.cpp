#include <iostream>

using namespace std;

int position;

int partition( int arr[], int left, int right ){

	if(left==right){
		return 1;
	}

	int pivot = arr[left];

	int boundary1 = left+1, boundary2 = left+1;

	for(int k=left+1; k<=right; k++){

		if(arr[k]<pivot){
			swap( arr[boundary1], arr[k] );
			boundary1++;
			boundary2++;
		}
		else{
			boundary2++;
		}
	}
	swap( arr[left], arr[boundary1-1] );

	
	

	return boundary1-left;
}

int get(int arr[], int left, int right, int i){

	int j = partition(arr, left, right);

	// for(int k=left; k<=right; k++){
	// 	cout<< arr[k] <<",";
	// }
	// cout<<endl;
	// cout<<j<<","<<position<<endl;
	// cout<<endl;

	if(j==position){
		return arr[left+j-1];
	}
	else if(j>position){
		position = i;
		get(arr, left, left+j-2, i);
	}
	else{
		position = i-j;
		get(arr, left+j, right, i-j);
	}
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int* arr = new int[n]();

		for(int k=0; k<n; k++)
			cin>>arr[k];

		int i;
		cin>>i;

		position = i;

		cout<< get(arr, 0, n-1, i)<<endl;

	}

	return 0;
}