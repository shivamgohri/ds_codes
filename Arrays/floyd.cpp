// UNIQUE NUMBER, ALL
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        if(nums.empty()){
            return -1;
        }  
        
        int slow = nums[0], fast = nums[nums[nums[0]]];
        
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        int front = nums[0], back = slow;
        
        while(front!=back){
            front = nums[front];
            back = nums[back];
        }
        
        return front;        
    }
};


void testcases(){



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