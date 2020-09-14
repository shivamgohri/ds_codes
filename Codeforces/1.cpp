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


void solve(vector<int>& cost, ull val, int n, ull& ans){

	int flag = 0;

	for(int i=0; i<cost.size(); i++){

		if(cost[i] <= n){
			flag = 1;
			solve(cost, val*10 + (i+1), n-cost[i], ans);
		}		
	}

	if(flag==0){
		ans = max(ans, val);
	}

	return;
}



void testcases(){

	int n;
	cin>> n;

	vector<int> cost(9, 0);

	for(int i=0; i<9; i++){
		cin>> cost[i];
	}

	ull ans = 0;
	solve(cost, 0, n, ans);

	if(ans==0){
		cout<< -1 <<endl;
	}
	else{
		cout<< ans <<endl;
	}
}



int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
	}

	return 0;
}