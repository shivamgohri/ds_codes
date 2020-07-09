#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

void invert(TreeNode* &root){
    
    if(root==NULL){
        return;
    }
    
    TreeNode* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invert(root->left);
    invert(root->right);
    
    return;
}    

TreeNode* invertTree(TreeNode* root) {
    
    if(root==NULL){
        return root;
    }
    
    invert(root);
    
    return root;
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