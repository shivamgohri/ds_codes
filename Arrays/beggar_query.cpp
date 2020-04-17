#include <iostream>

using namespace std;

int main(){

	int n;
	cin>> n; 

	int* arr = new int[n]();

	int k;
	cin>> k;

	while(k--){

		int start, end, money;       //start and end are indexes
		cin>> start >>end >>money;

		arr[start] += money;
		arr[end+1] += -money;
	}

	for(int i=1; i<n; i++){

		arr[i] = arr[i-1]+arr[i];

	}

	for(int i=0; i<n; i++){
		cout<< arr[i] <<" ";
	}

	return 0;
}