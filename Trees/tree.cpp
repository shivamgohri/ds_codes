#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		data = d;
		left = right = NULL;
	}

	int height(Node* root){
		if(root==NULL){return 0;}
		return max(height(root->left), height(root->right)) + 1;
	}
};


void printPre(Node* root){

	stack<Node*> s;

	while( root!=NULL || !s.empty() ){

		if(root!=NULL){
			cout<< root->data <<" ";
			s.push(root);
			root = root->left;
		}
		else{
			Node* temp = s.top();
			s.pop();
			root = temp->right;
		}
	}

	cout<<endl;
	return;
}

void printIn(Node* root){

	stack<Node*> s;

	while(root!=NULL || !s.empty()){

		if(root!=NULL){
			s.push(root);
			root = root->left;
		}
		else{
			Node* temp = s.top();
			s.pop();
			cout<< temp->data <<" ";
			root = temp->right;
		}
	}

	cout<<endl;
	return;
}


void testcases(){

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	printIn(root);

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