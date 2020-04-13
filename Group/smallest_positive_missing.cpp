#include <iostream>

using namespace std;

int main(){

	//LET CONSTRAINTS BE
	// 1<= N <= 10^6
	// 1<= array[i] <= 10^6

	int n;
	cin>> n;

	int* arr = new int[1000000]();

	for(int i=0; i<n; i++){
		int temp;
		cin>> temp;
		arr[temp-1]++;
	}

	for(int i=0; i<1000000; i++){
		if(arr[i]==0){
			cout<< i+1 <<endl;
			break;
		}
	}

	return 0;
}