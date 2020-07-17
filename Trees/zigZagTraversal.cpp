#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
    vector<vector<int> > ans;

    if(root==NULL){
        return ans;
    }
    
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    s1.push(root);
    vector<int> t;
    t.push_back(root->val);
    ans.push_back(t);

    while( !s1.empty() || !s2.empty() ){

        if(s2.empty()){

            TreeNode* temp;
            vector<int> x;

            while( !s1.empty() ){
                temp = s1.top();
                s1.pop();

                if(temp->right!=NULL){
                    x.push_back(temp->right->val);
                    s2.push(temp->right);
                }

                if(temp->left!=NULL){
                    x.push_back(temp->left->val);
                    s2.push(temp->left);
                }
            }
            if(!x.empty())
            ans.push_back(x);
        }
        else if(s1.empty()){

            TreeNode* temp;
            vector<int> x;

            while( !s2.empty() ){
                temp = s2.top();
                s2.pop();

                if(temp->left!=NULL){
                    x.push_back(temp->left->val);
                    s1.push(temp->left);
                }

                if(temp->right!=NULL){
                    x.push_back(temp->right->val);
                    s1.push(temp->right);
                }
            }
            if(!x.empty())
            ans.push_back(x);
        }
    }

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