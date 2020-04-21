//https://practice.geeksforgeeks.org/problems/equal-sum/0

#include <iostream>

using namespace std;

int main(){

	int t;
	cin>> t;

	while(t--){

		int n;
		cin>> n;

		int* arr = new int[n]();

		for(int i=0; i<n; i++)
			cin>> arr[i];

		int tsum = 0;

		for(int i=0; i<n; i++)
			tsum += arr[i];

		int sum = 0, flag = 0;

		for(int i=1; i<n-1; i++){

			sum += arr[i-1];

			if(sum == (tsum-sum-arr[i]) ){
				cout<< "YES" <<endl;
				flag = 1;
				break;
			}

		}

		if(flag == 0){
			cout<< "NO" <<endl;
		}

	}

	return 0;
}