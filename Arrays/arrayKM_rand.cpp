// take array k times and find all(repeatitions allowed) subarrays with sum less than or equal to M
// input [1 4 2 3] K=2, M=5
//output = 7 ( 1 , 4 ,2 ,3 ,1 4, 2 3, 3 1 )
//2- input [1 1] K=3, M=8
//ans = 21 (all subarrays)

#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	int k, m;
	cin>> k >> m;

	int* pref = new int[k*n]();

	int count = 0;
	map<int, int> ma;

	int ans = 0;

	for(int i=0; i<k*n; i++){

		pref[i] = arr[i%n];
		count += pref[i];
		pref[i] = count;

		if(pref[i]<=m){
			ans++;
		}

		auto it = ma.begin();
		while(it!=ma.end()){
			if( pref[i]-(it->first)<=m ){
				ans += it->second;
			}
			it++;
		}

		ma[pref[i]]++;

	}


	// for(int i=0; i<k*n; i++){

	// 	if(pref[i]<=m){
	// 		ans++;
	// 	}

	// 	auto it = ma.begin();
	// 	while(it!=ma.end()){
	// 		if( pref[i]-(it->first)<=m ){
	// 			ans += it->second;
	// 		}
	// 		it++;
	// 	}

	// 	ma[pref[i]]++;

	// }


	cout<< ans <<endl;
}