//https://practice.geeksforgeeks.org/problems/large-factorials/0

#include <iostream>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>> n;

		double fact = 1;
		int power = 0;

		for(int i = 1; i<=n; i++){

			fact = fact*i;

			while( (int)fact>9 ){
				power++;
				fact = fact/10;
			}

		}

		cout<< (int)fact <<" "<< power <<endl;

	}

}