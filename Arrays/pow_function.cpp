#include <iostream>

using namespace std;

double myPow(double x, int n) {
        
    double temp; 
    if(n == 0) 
        return 1; 
    temp = myPow(x, n / 2); 
    if (n % 2 == 0) 
        return temp * temp; 
    else
    { 
        if(n > 0) 
            return x * temp * temp; 
        else
            return (temp * temp) / x; 
    }     
}

int main(){

	double x;
	cin>> x;

	int n;
	cin>> n;

	cout<< myPow(x,n)<< endl;

	return 0;
}