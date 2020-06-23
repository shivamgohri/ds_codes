#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5


void testcases(){

	int n;
	cin>> n;

	int high = n;

	int arr[n] = {0};

	for(int i=0; i<n; i++){
		arr[i] = i+1;
	}

	int divisors[high+1] = {0};

	for(int i=0; i<n; i++){

		for(int j=1; j<=sqrt(arr[i]); j++){
			if(arr[i]%j==0){
				divisors[j]++;

				if( j!=(arr[i]/j) ){
					divisors[arr[i]/j]++;
				}
			}
		}
	}

	for(int i=high; i>=1; i--){
		if(divisors[i]>1){
			cout<< i;
			return;
		}
	}

	cout<< 1;
	return;
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}