#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define ip(arr) for(int i=0; i<arr.size(); i++) cin>>arr[i];
#define ip1(arr) for(int i=1; i<=arr.size(); i++) cin>>arr[i];
#define op(arr) for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" "; cout<<endl;

#define MAX 10000000
#define mod 100000007


void solve(vector<int> num){
	if(nums.size()<2){
	    return;
	}

	int val = -1, indx;

	for(int i=nums.size()-1; i>=1; i--){            
	    if( nums[i]<=nums[i-1] ){
	        
	    }
	    else{
	        val = nums[i-1];
	        indx = i;
	        break;
	    }            
	}

	if(val==-1){
	    return;
	}

	for(int i=nums.size()-1; i>=1; i--){            
	    if( nums[i]<=nums[i-1] ){
	        if( nums[i]>val && nums[i]<nums[indx] ){
	            indx = i;
	        }
	    }
	    else{
	        swap(nums[i-1], nums[indx]);
	        sort(nums.begin()+i, nums.end());
	        return;
	    }            
	}
}


void testcases(){

	int n;
	cin>> n;

	vector<int> num;

	while(n>0){
		int last = n%10;
		n = n/10;
		num.push_back(last);
	}

	reverse(num.begin(), num.end());

	solve(num);

	for(auto n:num){
		cout<<n;
	}

	cout<<endl;

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