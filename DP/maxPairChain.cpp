/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

bool compare(vector<int> p1, vector<int> p2){
	if(p1[0]==p2[0]){
		return p1[1]<p2[1];
	}
	return p1[0]<p2[0];
}


int findLongestChain(vector<vector<int>>& pairs) {

	if(pairs.size()==0){
		return 0;
	}

	sort(pairs.begin(), pairs.end(), compare);

	vector<int> count(pairs.size(), 1);
	int max_indx = 0;

	for(int i=1; i<pairs.size(); i++){
		for(int j=0; j<i; j++){

			if( pairs[j][1] < pairs[i][0] ){
				if( count[j]+1>count[i] ){
					count[i] = count[j] + 1;
				}
			}

			if(count[i]>count[max_indx]){
				max_indx = i;
			}

		}
	}

	return count[max_indx];
        
}


void testcases(){



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