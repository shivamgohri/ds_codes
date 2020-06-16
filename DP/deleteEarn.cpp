/*
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:

Input: nums = [3, 4, 2]
Output: 6
Explanation: 
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int deleteAndEarn(vector<int>& nums) {

	if(nums.empty()){
        return 0;
    }

    sort(nums.begin(), nums.end());

    vector<int> count;
    count = nums;

    int max_indx = 0;

    for(int i=1; i<nums.size(); i++){
        int best = nums[i];
        for(int j=0; j<i; j++){

            if( nums[j]+1!=nums[i] ){
                int n = count[i] + count[j];
                best = max(n, best);
            }

        }
        count[i] = best;

        if(count[i]>count[max_indx]){
            max_indx = i;
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