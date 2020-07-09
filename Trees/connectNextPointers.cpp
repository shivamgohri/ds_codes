#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

void connect(Node *p) {
    
    if(p==NULL){
        return;
    }
    
    p->nextRight = NULL;
    
    Node* parent = p;
    Node* childHead = NULL;
    Node* curr = NULL;
    
    while(parent!=NULL){
        
        if(parent->left!=NULL){
            if(childHead==NULL){
                childHead = parent->left;
                curr = childHead;
            }
            else{
                curr->nextRight = parent->left;
                curr = parent->left;
            }
        }
        
        if(parent->right!=NULL){
            if(childHead==NULL){
                childHead = parent->right;
                curr = childHead;
            }
            else{
                curr->nextRight = parent->right;
                curr = parent->right;
            }
        }
        
        parent = parent->nextRight;
        
        if(parent==NULL){
            if(childHead==NULL){
                break;
            }
            else{
                curr->nextRight = NULL;
                parent = childHead;
                childHead = curr = NULL;
            }
        }
        
    }
    
    return;
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