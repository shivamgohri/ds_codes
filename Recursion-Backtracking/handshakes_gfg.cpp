//https://practice.geeksforgeeks.org/problems/handshakes/0

#include <iostream>
using namespace std;

int handshakeWays(int n){

	if(n==2){
		return 1;
	}

	int temp = (n-3)/2;

	int ans = 0, j = 2;

	while(temp--){
		ans += handshakeWays(j) * handshakeWays(n-j-2);
		j = j+2;
	}

	return ans + 2*handshakeWays(n-2);
}

int main() {

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		if(n<2){
			cout<<0<<endl;
		}
		else{

			cout<< handshakeWays(n) <<endl;

		}
	}

	return 0;
}