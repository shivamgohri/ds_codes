#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        
    vector<int> ans(nums.size(),1);
    
    for(int i=1; i<nums.size(); i++){
        ans[i] = ans[i-1]*nums[i-1];
    }
    
    int prev=1;
    for(int i=ans.size()-1; i>=0; i--){
        ans[i] = ans[i]*prev;
        prev = prev*nums[i];
    }
    
    return ans;        
}

int main(){

	int n;
	cin>> n;

	vector<int> nums(n,0);

	for(int i=0; i<n; i++){
		cin>> nums[i];
	}

	vector<int> result = productExceptSelf(nums);

	for(int i=0; i<result.size(); i++){
		cout<< result[i] <<" ";
	}

	cout<<endl;

	return 0;
}