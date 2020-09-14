#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


void testcases(){

	int batches, minTime;
	cin>> batches >> minTime;

	vector<int> arr(batches, 0);

	for(int i=0; i<batches; i++){
		cin>> arr[i];
	}

	if(batches==1){
		cout<< minTime*arr[0];
		return;
	}

	sort(arr.begin(), arr.end(), greater<int>() );

	int ans = 0;

	int x = 0;

	while(x<arr.size()){

		if(arr[x]==0){
			x++;
		}
		else{

			ans += minTime;

			int t = 1, i = x+1;

			while( i<arr.size() && t<=minTime ){
				if(arr[i]==0){
					i++;
				}
				else{
					arr[i]--;
					i++;
					t++;
				}
			}

			arr[x]--;
		}
	}

	cout<< ans;
	return;
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}