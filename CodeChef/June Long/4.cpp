#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	ull n;
	cin>> n;

	if( n&1 ){
		cout<< n/2;
		return;
	}
	else{

		if( n%4!=0 ){
			cout<< n/4;
			return;
		}
		else{

			while(n>0){
		        if(n&1==1){
		            break;
		        }
		        n = n>>1;
		    }

		    n = n>>1;
		    cout<< n;
		    return;
		}

	}



}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}