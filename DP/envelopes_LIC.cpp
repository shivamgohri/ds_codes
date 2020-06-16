/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


bool compare(vector<int>&v1, vector<int>&v2){
	if(v1[0]==v2[0]){
		return v1[1]<v2[1];
	}
	return v1[0]<v2[0];
}


int maxEnvelopes(vector<vector<int>>& envelopes) {

	if(envelopes.size()==0){
        return 0;
    }

	sort(envelopes.begin(), envelopes.end(), compare);

	vector<int> count(envelopes.size(), 1);

	int max_indx = 0;

	for(int i=1; i<envelopes.size(); i++){
		for(int j=0; j<i; j++){

			if( envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1] ){
				if( count[j]+1>count[i] ){
					count[i] = count[j] + 1;
				}
			}

			if(count[max_indx]<count[i]){
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