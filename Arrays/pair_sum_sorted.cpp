#include <iostream>

using namespace std;
// WORKS FOR SORTED ARRAY ONLY

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int key;
	cin>> key;

	int i=0, j=n-1;
	while(i<j){
		if(arr[i]+arr[j]<key){
			i++;
		}
		else if(arr[i]+arr[j]>key){
			j--;
		}
		else{
			cout<< "Pair of " <<arr[i]<< " and "<<arr[j]<<endl;
			i++;
			j--;
		}
	}

	return 0;
}