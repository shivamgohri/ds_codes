#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5


int solve(TreeNode* root, int& res){
    if(root==NULL){
        return 0;
    }
    
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    
    int max_single = max( max(l, r) + root->val, root->val);
    int max_top = max(max_single, l+r+root->val);
    
    res = max(res, max_top);
    
    return max_single;
}

int maxPathSum(TreeNode* root) {
    
    if(root==NULL){
        return 0;
    }
    
    int res = INT_MIN;
    solve(root, res);
    
    return res;        
}


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