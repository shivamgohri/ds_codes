`#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	int arr_new[ (2*n)+1 ] = {};
	int count = 0, max_length=0;

	std::fill_n(arr_new, (2*n)+1, -n);

	arr_new[n] = -1;

	for(int i=0; i<n; i++){
		count = count + (arr[i]==1?1:-1);

		if( arr_new[count+n] >= -1 ){
			max_length = max( max_length, i-arr_new[count+n] );
		}
		else{
			arr_new[count+n] = i;
		}
	}

	cout<< max_length <<endl;

	return 0;	
}