//helpful in finding frequencies in sorted array!
// O(LogN)

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int key;
	cin>> key;

	// cout<< binary_search(arr, arr+n, key) <<endl;

	int* lb = lower_bound(arr, arr+n, key);
	// cout<< (lb-arr) <<endl;

	int* ub = upper_bound(arr, arr+n, key);
	// cout<< (ub-arr) <<endl;

	cout<< (ub-lb) <<endl;

	return 0;
}