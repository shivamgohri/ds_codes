#include <iostream>

using namespace std;

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	int result = 0;
	int left_max = 0, right_max = 0;
	int left = 0, right = n-1;

	while(left<=right){

		if(arr[left]<arr[right]){

			if(arr[left]<left_max){
				result += left_max-arr[left];
			}
			else{
				left_max = arr[left];
			}
			left++;
		}
		else{

			if(arr[right]<right_max){
				result += right_max-arr[right];
			}
			else{
				right_max = arr[right];
			}
			right--;
		}
	}

	cout<< result <<endl;

	return 0;
}