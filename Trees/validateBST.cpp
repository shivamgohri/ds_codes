#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

bool solve(TreeNode* root, long long int* prev){
        if(root==NULL){
        return true;
    }
    
    bool l = solve(root->left, prev);
    
    if( root->val > *prev ){
        *prev = root->val;
    }
    else{
        return false;
    }
        
    bool r = solve(root->right, prev);
    
    return l && r;        
}

bool isValidBST(TreeNode* root) {
    if(root==NULL){
        return true;
    }
    
    long long int prev = -200000000000;
    
    return solve(root, &prev);
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