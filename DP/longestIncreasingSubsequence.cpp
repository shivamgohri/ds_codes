/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
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

	if(n==0){
		cout<< 0;
		return;
	}

	vector<int> nums(n,0);

	for(int i=0; i<n; i++)
		cin>> nums[i];

	vector<int> count(nums.size(),1);

	int max_indx = 0;

	for(int i=1; i<nums.size(); i++){

		for(int j=0; j<i; j++){
			if( nums[j]<nums[i] ){
				if( count[j]+1>count[i] ){
					count[i] = count[j]+1;
				}
			}
		}

		if( count[max_indx]<count[i] ){
			max_indx = i;
		}
	}

	cout<< count[max_indx];
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