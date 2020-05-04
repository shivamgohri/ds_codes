//https://practice.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order/0\

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void numbers(int output, int last, int position, int size){

	if(last>9) {return;}

	if(position==size){
		cout<<output<<" ";
		return;
	}

	for(int i=last+1; i<=(10-size+position); i++){
		numbers( (output*10)+i, i, position+1, size );
	}

	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int output = 0;

		numbers(output, 0, 0, n);
		cout<<endl;
	}

	return 0;
}