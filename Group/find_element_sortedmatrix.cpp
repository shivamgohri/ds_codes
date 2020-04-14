#include <iostream>

using namespace std;

int main(){

	int m, n; //m rows, n columns
	cin>> m >> n;

	int** arr = new int*[m]();
	for(int i=0; i<m; i++)
			arr[i] = new int[n]();

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>> arr[i][j];

	int element;
	cin>> element;

	int i=0, j=n-1, flag=0;
	while( (i>=0 && i<m) && (j>=0 && j<n) ){
		if(element > arr[i][j]){
			i++;
		}
		else if(arr[i][j] > element){
			j--;
		}
		else{
			flag = 1;
			cout<< i <<" "<< j <<endl;
			break;
		}
	}

	if(flag==0){
		cout<< "Element not found" <<endl;
	}

}