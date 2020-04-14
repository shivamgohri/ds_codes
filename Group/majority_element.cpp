#include <iostream>

using namespace std;
// MOORE'S VOTING ALGORITHM
// O(n) for O(1) space

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	int maj_indx = 0, count = 1;
	for(int i=1; i<n; i++){
		if(arr[maj_indx]==arr[i]){
			count++;
		}
		else{
			count--;
		}

		if(count==0){
			maj_indx = i;
			count = 1;
		}
	}

	count = 0;
	for(int i=0; i<n; i++){
		if(arr[i]==arr[maj_indx]){
			count++;
		}
	}

	if(count>n/2){
		cout<< arr[maj_indx] <<endl;
	}
	else{
		cout<< "No such element" <<endl;
	}
}