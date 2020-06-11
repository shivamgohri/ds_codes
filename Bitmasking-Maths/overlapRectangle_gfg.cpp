#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5


void testcases(){

	int x,y;

	cin>> x >> y;

	pair<int, int> l1 = mp(x,y);

	cin>> x >> y;

	pair<int, int> r1 = mp(x,y);

	cin>> x >> y;

	pair<int, int> l2 = mp(x,y);

	cin>> x >> y;

	pair<int, int> r2 = mp(x,y);

	if( l1.first>r2.first || l2.first>r1.first ){
		cout<< 0;
		return;
	}

	if( r1.second>l2.second || r2.second>l1.second ){
		cout<< 0;
		return;
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