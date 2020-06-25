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

	double angle = 360.00/n;

    int a = 90 / angle;

    double prod = a*angle;

    if( prod == 90 ){
        cout<< "YES";
    }
    else{
        cout<< "NO";
    }
    
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