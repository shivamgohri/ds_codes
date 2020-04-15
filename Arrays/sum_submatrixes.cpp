#include <iostream>

using namespace std;

int main(){

	int m, n;
	cin>> m>> n;  
	//m rows, n columns

	int** a = new int*[m];
	for(int i = 0; i < m; i++)
    	a[i] = new int[n];

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>> a[i][j];
		}
	}

	int sum = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			sum += ((i+1)*(j+1)*(m-i)*(n-j))*a[i][j];
		}
	}

	cout<< sum <<endl;
}