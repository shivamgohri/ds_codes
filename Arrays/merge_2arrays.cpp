//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0

#include <iostream>
#include <vector>

using namespace std;

int main(){

	int t;
	cin>> t;

	while(t--){

		int n1, n2;
		cin>> n1 >>n2;

		vector<long int> arr1(n1,0);
		vector<long int> arr2(n2,0);

		for(int i=0; i<n1; i++)
			cin>> arr1[i];

		for(int i=0; i<n2; i++)
			cin>> arr2[i];

		int i = 0, j = 0;

		while( i<n1 && j<n2 ){

			if( arr1[i] <= arr2[j] ){
				i++;
			}
			else{
				swap( arr1[i], arr2[j] );
				
				int temp = j;
				while( arr2[temp] > arr2[temp+1] && temp+1<n2 ){
					swap( arr2[temp], arr2[temp+1] );
					temp++;
				}

				i++;
			}

		}

		for(int i=0; i<n1; i++)
			cout<< arr1[i] <<" ";

		for(int i=0; i<n2; i++)
			cout<< arr2[i] <<" ";
		cout<<endl;

	}


	return 0;
}