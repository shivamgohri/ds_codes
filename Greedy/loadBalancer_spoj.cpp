#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back


void testcases(int n){

	int* arr = new int[n]();

	int sum = 0;

	for(int i=0; i<n; i++){
		cin>> arr[i];
		sum += arr[i];
	}

	if( sum%n!=0 ){
		cout<<-1;
		return;
	}

	int expected = sum/n;

	int curr = 0, ans = 0;

	for(int i=0; i<n; i++){

		curr += arr[i];
		int c = (i+1)*expected;

		ans = max( ans, abs(curr-c) );
	}

	cout<< ans;

}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t){
		int n;
		cin>> n;
		if(n==-1){
			break;
		}
		testcases(n);
		cout<<endl;
	}

	return 0;
}