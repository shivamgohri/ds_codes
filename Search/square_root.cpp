//O(logN + times(precision)*10 )

#include <iostream>

using namespace std;

float find_root(int n){

	int s = 0;
	int e = n;

	float ans = -1;

	while(s<=e){

		int mid = (s+e)>>1;

		if( (mid*mid) == n ){
			return mid;
		}
		else if( (mid*mid) > n ){
			e = mid - 1;
		}
		else{
			ans = mid;
			s = mid + 1;
		}
	}

	float inc = 0.1;


	for(int times = 1; times<=6; times++){

		while(ans*ans<=n){
			ans += inc;
		}
		
		ans = ans-inc;
		inc = inc/10;
	}


	return ans;
}

int main(){

	int n;
	cin>> n;

	cout<< find_root(n) <<endl;

	return 0;
}