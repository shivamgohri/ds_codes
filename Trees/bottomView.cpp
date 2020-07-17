#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5


void solve(Node* root, unordered_map<int, pair<int, int> >& m, int d, int l, int& left, int& right){
    if(root==NULL){
        return;
    }
    
    if( m.find(d)!=m.end() ){
        if( l>=m[d].first ){
            m[d].first = l;
            m[d].second = root->data;
        }
    }
    else{
        m[d] = make_pair(l, root->data);
    }
    
    left = min(left, d);
    right = max(right, d);
    
    solve(root->left, m, d-1, l+1, left, right);
    solve(root->right, m, d+1, l+1, left, right);
    return;
}

vector <int> bottomView(Node *root){
   
   if(root==NULL){
       vector<int> ans;
       return ans;
   }
   
   unordered_map<int, pair<int, int> > m;
   
   int l = 0, r = 0;
   
   solve(root, m, 0, 0, l, r);
   
   vector<int> ans(r-l+1, 0);
   
    for(auto it:m){
      ans[it.first-l] = it.second.second;
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