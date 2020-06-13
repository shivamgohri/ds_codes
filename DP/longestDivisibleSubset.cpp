/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

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

	vector<int> nums(n,0);

	for(int i=0; i<n; i++){
		cin>> nums[i];
	}

	vector<int> ans;

	if(n==0){
		return;
	}

	sort(nums.begin(), nums.end());  //so that divisor comes first

	vector<int> count(nums.size(),1);
	vector<int> prev(nums.size(),-1);

	int max_indx = 0;

	for(int i=1; i<nums.size(); i++){

		for(int j=0; j<i; j++){

			if( nums[i]%nums[j]==0 ){
				if( count[j]+1>count[i] ){
					count[i] = count[j]+1;
					prev[i] = j;
				}
			}
		}

		if(count[max_indx]<count[i]){
			max_indx = i;
		}
	}

	int k = max_indx;

	while(k>=0){
		ans.pb(nums[k]);
		k = prev[k];
	}

	for(int i=0; i<ans.size(); i++){
		cout<< ans[i] <<",";
	}
	cout<< endl;


}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}