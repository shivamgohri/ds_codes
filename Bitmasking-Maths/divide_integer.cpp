//https://www.interviewbit.com/problems/divide-integers/

#include <iostream>
#include <cmath>

using namespace std;

#define ll unsigned long long

int main(){

	int divident, divisor;
	cin>> divident >>divisor;

	if(divisor==1){
		return divident;
	}

	int sign = 1;

	if(divident<0){
		sign = -sign;
	}
	if(divisor<0){
		sign = -sign;
	}

	if(divident==INT_MIN){
		divident = INT_MAX;
	}
	if(divisor==INT_MIN){
		divisor = INT_MAX;
	}

	divident = abs(divident);
	divisor = abs(divisor);

	ll div = divisor;

	div = div<<32;

	int quotient = 0, remainder = divident;

	for(int i=0; i<=32; i++){

		long long diff = remainder - div;

		if( diff < 0 ){
			div = div>>1;
			quotient = quotient<<1;
		}
		else{
			remainder = (int)diff;
			quotient = quotient<<1;
			quotient++;
			div = div>>1;
		}
	}

	quotient = sign*quotient;
	remainder = sign*remainder;

	cout<<quotient<<" "<<remainder<<endl;

	return 0;  
}
