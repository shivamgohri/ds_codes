#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases1(){						// i<=j<=k maximize a*arr[i] + b*arr[j] + c*arr[k]

	int n;
	cin>> n;

	vector<int> arr(n, 0);

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int a, b, c;
	cin>> a >> b >> c;

	vector<int> l(n, 0);
	vector<int> r(n, 0);

	l[0] = a*arr[0];
	for(int i=1; i<n; i++){
		l[i] = max( l[i-1], a*arr[i]);
	}

	r[n-1] = c*arr[n-1];
	for(int i=n-2; i>=0; i--){
		r[i] = max( r[i+1], c*arr[i]);
	}

	int ans = INT_MIN;

	for(int i=0; i<n; i++){
		ans = max( ans, l[i] + r[i] + b*arr[i]);
	}

	cout<< ans;
	return;
}

void testcases(){								// i<j<k maximize a*arr[i] + b*arr[j] + c*arr[k]

	int n;
	cin>> n;

	vector<int> arr(n, 0);

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int a, b, c;
	cin>> a >> b >> c;

	vector<int> l(n, 0);
	vector<int> r(n, 0);

	l[0] = 0;
	for(int i=1; i<n; i++){
		l[i] = ( (a*l[i-1])>=(a*arr[i]) ? (i-1) : i ); 
	}

	r[n-1] = n-1;
	for(int i=n-2; i>=0; i--){
		r[i] = ( (c*arr[i])>=(c*r[i+1]) ? i : (i+1) );
	}

	int ans = INT_MIN;

	for(int i=1; i<=n-2; i++){
		ans = max(ans, a*arr[l[i-1]] + b*arr[i] + c*arr[r[i+1]]);
	}

	cout<< ans;
	return;
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