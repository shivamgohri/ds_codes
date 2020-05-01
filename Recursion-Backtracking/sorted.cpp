#include <iostream>

using namespace std;

bool sorted(int arr[], int left, int right){

	if(left == right){
		return true;
	}

	return ( arr[left] < arr[left+1] ) && ( sorted(arr, left+1, right) );
}

int main(){

	int n;
	cin>>n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	cout<< sorted(arr, 0, n-1) <<endl;

}