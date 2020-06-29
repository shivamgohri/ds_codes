#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	int n;
	cin>> n;

	vector<int> arr(n, 0);

	for(int i=0; i<n; i++)
		cin>> arr[i];

	vector<int> left(n, 1);
	vector<int> right(n, 1);

	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[j]<arr[i]){
				left[i] = max(left[i], left[j]+1);
			}
		}
	}

	for(int i=n-2; i>=0; i--){
		for(int j=n-1; j>i; j--){
			if(arr[j]<arr[i]){
				right[i] = max(right[i], right[j]+1);
			}
		}
	}

	int ans = 1;

	for(int i=0; i<n; i++){
		int n = left[i] + right[i] - 1;
		ans = max(n, ans);
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