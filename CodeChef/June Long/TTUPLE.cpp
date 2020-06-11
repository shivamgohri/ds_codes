#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	ll old[3], newarr[3];

	for(int i=0; i<3; i++)
		cin>> old[i];

	for(int i=0; i<3; i++)
		cin>> newarr[i];

	int diff[3], div[3];

	int zero = 0;

	for(int i=0; i<3; i++){
		diff[i] = newarr[i] - old[i];
		if(diff[i]==0){
			zero++;
		}
	}

	if(zero==3){
		cout<<0<<endl;
		return;
	}








	for(int i=0; i<3; i++){

		if( diff[i]!=0 ){
			if( old[i]!=0 && newarr[i]!=0 ){
				if( diff[i]%old[i]==0 ){
					div[i] = newarr[i]/old[i];
					continue;
				}
			}
		}
		div[i] = 0;
	}


	int best = 0;

	for(int i=0; i<2; i++){
		int temp = 1;
		for(int j=i+1; j<3; j++){
			if( diff[i]==diff[j] && diff[i]!=0 && diff[j]!=0 ){
				temp++;
			}
		}
		best = max(temp, best);
	}

	for(int i=0; i<2; i++){
		int temp = 1;
		for(int j=i+1; j<3; j++){
			if( div[i]==div[j] && (div[i]!=1&&div[i]!=0) && (div[j]!=1&&div[j]!=0) ){
				temp++;
			}
		}
		best = max(temp, best);
	}

	int ans = 3 - best + 1 - zero;

	cout<< ans <<endl;

	// for(int i=0; i<3; i++){
	// 	cout<< diff[i] <<",";
	// }
	// cout<<endl;

	// for(int i=0; i<3; i++){
	// 	cout<< div[i] <<",";
	// }
	// cout<<endl;


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