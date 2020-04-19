#include <iostream>
#include <vector>

using namespace std;
// O(max(queries, n^2)) for O(n^2){input matrix is read only} else O(1){like in this, changeable input matrix}

int main(){

	int n, m; //n rows, m columns
	cin>> n >>m;

	int arr[n][m] = {0};

	for(int i=0 ;i<n ;i++)
		for(int j=0; j<m; j++)
			cin>> arr[i][j];

	//calculate prefix sum array of 2d matrix
		// 0 0 0 
		// 0 0 0
		// 0 0 0

	for(int i=1; i<n; i++)
		arr[i][0] = arr[i-1][0] + arr[i][0];

	for(int i=1; i<m; i++)
		arr[0][i] = arr[0][i-1] + arr[0][i];

	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}

	
	int k;
	cin>> k;

	while(k--){

		int tli, tlj, bri, brj;
		cin>> tli >> tlj >> bri >> brj;

		cout<< arr[bri][brj] - (tlj-1>=0?arr[bri][tlj-1]:0) - (tli-1>=0?arr[tli-1][brj]:0) + ( (tli-1>=0)&&(tlj-1>=0)?arr[tli-1][tlj-1]:0 ) <<endl;

	}

	return 0;
}