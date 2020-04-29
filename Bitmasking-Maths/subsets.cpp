#include <iostream>

using namespace std;

void filter(char arr[], int n){

	int j=0;
	while(n>0){
		int last_bit = n&1;

		if(last_bit==1){
			cout<<arr[j];
		}
		j++;
		n = n>>1;
	}

	cout<<endl;
	return;
}

void printSubsets(char arr[], int n){

	int a = 1<<n;

	for(int i=0; i<a; i++){
		filter(arr, i);
	}
	return;
}

int main(){

	int n;
	cin>> n;

	char* arr = new char[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	printSubsets(arr, n);

	return 0;
}