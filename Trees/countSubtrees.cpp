#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

int solve(Node* root, int* ans, int x){
    if(root==NULL){
        return 0;
    }
    
    int l = solve(root->left, ans, x);
    int r = solve(root->right, ans, x);
    
    if( l+r+root->data == x ){
        *ans = *ans + 1;
    }
    
    return l+r+root->data;
}

int countSubtreesWithSumX(Node* root, int x){
    if(root==NULL){
        return 0;
    }
    int ans = 0;
    int s = solve(root, &ans, x);
    return ans;
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