#include <iostream>

using namespace std;

double power(double x, int n){

	double temp;

	if(n==0){return 1;}
	temp = power(x, n/2);

	if( n%2 == 0 ){
		return temp*temp;
	}
	else{
		if( n>0 ){
			return x*temp*temp;
		}
		else{
			return (temp*temp)/x;
		}
	}

}

int main(){

	double a;
	int b;
	cin>> a >>b ;

	//a^b

	cout<< power(a, b) <<endl;

}