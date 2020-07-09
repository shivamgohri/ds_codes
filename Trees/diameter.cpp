#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

int diameter(TreeNode* root, int* h){
    if(root==NULL){
        *h = 0;
        return 0;
    }
    int lh = 0, rh = 0, ld = 0, rd = 0;
    ld = diameter(root->left, &lh);
    rd = diameter(root->right, &rh);
    
    *h = max(lh, rh) + 1;
    
    return max( lh+rh, max(ld, rd));
}

int diameterOfBinaryTree(TreeNode* root) {
    int h = 0;
    return diameter(root, &h);            
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