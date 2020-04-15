#include <iostream>
#include <cmath>

using namespace std;

int findMissing(int* arr, int n){

	int j=0;
	for(int i=0; i<n; i++){

		if(arr[i]<=0){
			swap(arr[i], arr[j]);
			j++;
		}
	}

	for(int i=j; i<n; i++){

		if( abs(arr[i])+j-1<n && arr[abs(arr[i])+j-1]>0 ){
			arr[abs(arr[i])+j-1] = -arr[abs(arr[i])+j-1];
		}
	}

	for(int i=j; i<=n; i++){
		if(i==n){
			return i+1-j;
		}
		if(arr[i]>0){
			return i+1-j;
		}
	}

}

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	cout<< findMissing(arr, n) <<endl;

	return 0;
}