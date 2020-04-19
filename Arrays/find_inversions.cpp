#include <iostream>

using namespace std;

long long merge(int* arr, int* temp, int left, int rstart, int end){

	long long inv = 0;
	int i = left, j = rstart, k = end;

	while(  )

}

long long findInv( int* arr , int* temp, int left, int right ){

	long long inv = 0;
	int mid = 0;

	if(right>left){

		mid = (left+right)/2;
		inv += findInv(arr, temp, left, mid);
		inv += findInv(arr, temp, mid+1, right);
		inv += merge(arr, temp, left, mid+1, right);
	}

	return inv;
}

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int* temp = new int[n]();

	long long result = findInv( arr, temp, 0, n-1 );

	cout<< result <<endl;

	return 0;
}