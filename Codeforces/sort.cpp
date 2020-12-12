#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define ip(arr) for(int i=0; i<arr.size(); i++) cin>>arr[i];
#define ip1(arr) for(int i=1; i<=arr.size(); i++) cin>>arr[i];
#define op(arr) for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" "; cout<<endl;

#define MAX 10000000
#define mod 100000007


void testcases(){

	int n, m;
	cin>> n >> m;

	vector<int> arr1(n);
	vector<int> arr2(m);

	for(int i=0; i<n; i++){
		cin>> arr1[i];
	}

	for(int i=0; i<m; i++){
		cin>> arr2[i];
	}

	op(arr1);
	op(arr2);

	int ans[n+m];

	int i = n-1, j = m-1, k = 0;

	while( i>=0 && j>=0 ){

		if(arr1[i]==arr2[j]){
			ans[k++] = arr1[i--];
		}
		else if(arr1[i]<arr2[j]){
			ans[k++] = arr2[j--];
		}
		else{
			ans[k++] = arr1[i--];
		}
	}

	while(i>=0){
		ans[k++] = arr1[i--];
	}

	while(j>=0){
		ans[k++] = arr2[j--];
	}

	for(int i=0; i<(n+m); i++){
		cout<< ans[i] << " ";
	}

	cout<< endl;
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