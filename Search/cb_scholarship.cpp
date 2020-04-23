#include <iostream>

using namespace std;

int main(){

	long int n,m,x,y;
	cin>>n>>m>>x>>y;

	long int s = 0;
	long int e = n;

	long int ans = 0;

	while(s<=e){

		long int mid = (s+e)/2;

		if( (mid*x) <= (m + (n-mid)*y ) ){
			ans = max(mid, ans);
			s = mid+1;
		}		
		else{
			e = mid-1;
		}
	}

	cout<< ans <<endl;

	return 0;
}