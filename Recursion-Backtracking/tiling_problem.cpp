// So this actually forms a kindof fibonacci series, 
// this practice is good for finding 1 queries but for large number of queries,
// its good to make a array before hand!

#include <iostream>

using namespace std;

int ways(int n, int x){

	if(n<=0) {return 0;}
	if( x>=1 && x<n ){return 1;}
	if(x == n){return 2;}

	return (ways(n, x-1) + ways(n, x-n) );
}

int main(){

	int n, x;
	cin>> n >>x;

	cout<< ways(n, x) <<endl;

}