#include <iostream>
#include <vector>

using namespace std;
// O(NLOGN)


long long merge( int arr[], int temp[], int left, int mid, int right ){

	int i = left;
	int j = mid;
	int k = left;

	long long inv = 0;
	while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv = inv + (mid - i); 
        } 
    } 

	while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i = left; i <= right; i++) 
        arr[i] = temp[i];

    return inv;
}

long long _merge( int arr[], int temp[], int left, int right ){

	int mid;
	long long inv = 0;
	if(right>left){

		mid = (left+right)/2;
		inv += _merge(arr, temp, left, mid );
		inv += _merge(arr, temp, mid+1, right);

		inv += merge( arr, temp, left, mid+1, right );
	}
	return inv;
}

long long findInversions( int arr[], int n ){
	
	int temp[n];
	return _merge( arr, temp, 0 , n-1 );
}


int main(){

	int n;
	cin>> n;

	int arr[n];

	for(int i=0; i<n; i++)
		cin>> arr[i];

	long long result = findInversions( arr, n );
	cout<< result <<endl;

	return 0;
}