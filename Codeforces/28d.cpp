#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5


void testcases(){

	int n, k;
	cin>> n >> k;

	map<int, int, greater<int> > dp;

	for(int i=0; i<n; i++){
		int x;
		cin>> x;
		dp[x]++; 
	}

	int i = 0, x = 0, ans = 0;
	auto it = dp.begin();

	while(!dp.empty()){

		if(it==dp.end()){
			it = dp.begin();
			continue;
		}

		if(it->second==0){
			auto temp = it;
			it++;
			dp.erase(temp);
			continue;
		}

		cout<< it->first <<" ";

		if( it->first%k==0 ){
			it->second--;
			it++;
		}
		else{

			if( (it->first+x)%k==0 ){
				ans++;
				x++;
				it->second--;
				it++;
			}
			else{
				x++;
				ans++;
			}
		}
	}

	cout<< ans;
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