#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

bool solve(Node* x, Node* y){
    if(x==NULL && y==NULL){
        return true;
    }
    
    if(x==NULL || y==NULL){
        return false;
    }
    
    return solve(x->left, y->right) && solve(x->right, y->left);
}

bool IsFoldable(Node* root){
    if(root==NULL){
        return true;
    }
    return solve(root->left, root->right);
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