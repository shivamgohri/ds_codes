#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

bool isIdentical(TreeNode* x, TreeNode* y){
    if(x==NULL && y==NULL){
        return true;
    }

    if(x==NULL || y==NULL){
        return false;
    }

    if( x->val!=y->val ){
        return false;
    }

    return isIdentical(x->left, y->left) && isIdentical(x->right, y->right);
}

bool isSubtree(TreeNode* S, TreeNode* T) { 
    if( T==NULL && S==NULL ){
        return true;
    }
    
    if(T==NULL || S==NULL){
        return false;
    }

    if(S->val == T->val){
        if( isIdentical(S, T) ){
            return true;
        }
    }

    return isSubtree(S->left, T) || isSubtree(S->right, T);        
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