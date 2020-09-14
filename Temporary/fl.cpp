#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


int solve(int n){

	int i = 0;
	while(n>0){
		int last = n%10;
		if(last==1){
			i++;
		}
		n = n/10;
	}

	return i;
}


int count(float n){

	int a = n;
	n = n - floor(n);

	while( !(ceil(n)==n) ){
		n = n * 10.0f;
	}

	cout<< a <<","<< n <<endl;
	int ans = solve(a) + solve((int)n);

	return ans;
}


void testcases(){
	
	float n;
	cin>> n;

	// cout<< (ceil(n)==n);

	cout<< count(n);
	return;
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}