#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

void solve(TreeNode* root, ull depth, ull position, ull* ans, unordered_map<ull, ull>& left){
	if(root==NULL){
		return;
	}

	if(left.find(depth)==left.end()){
		left[depth] = position;
	}

	*ans = max( *ans, position - left[depth] + 1 );
	solve(root->left, depth+1, position*2, ans, left);
	solve(root->right, depth+1, position*2 + 1, ans, left);
	return ans;
}

int widthOfBinaryTree(TreeNode* root) {

	ull ans = 0;
	unordered_map<ull, ull> left;

	solve(root, 0, 0, &ans, left);

	return (int)ans;        
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
