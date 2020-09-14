#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


class Node{
public:
	Node *parent;
	int data;
	bool isLocked;
	int count;
	vector<Node*> children;
	Node(int d, Node* p){
		data = d;
		parent = p;
		count = 0;
		isLocked = false;
		children.clear();
	}
};


bool isAnyAncestorLocked(Node* node){

	if(node==NULL){
		return false;
	}

	if(node->isLocked || node->count>0){
		return true;
	}

	return isAnyAncestorLocked(node->parent);
}


void lock(Node* node){

	if(node==NULL){
		return;
	}

	if(node->isLocked || node->count>0){
		return;
	}

	if( isAnyAncestorLocked(node)==false ){
		Node* temp = node->parent;

		while(temp!=NULL){
			temp->count += 1;
			temp = temp->parent;
		}

		node->isLocked = true;

		return;
	}

	return;
}

void printTree(Node* root){

	if(root==NULL){
		return;
	}

	cout<< root->data <<"-> ";

	for(auto child:root->children){
		cout<< child->data <<" ";
	}
	cout<< endl;

	for(auto child:root->children){
		printTree(child);
	}

	return;
}


void testcases(){

	//Root node as reference
	Node* root = new Node(5, NULL);

	root->children.push_back(new Node(4, root)); // [0]
	root->children.push_back(new Node(7, root)); // [1]
	root->children.push_back(new Node(8, root)); // [2]
	
	//4
	Node* temp = root->children[0];

	temp->children.push_back(new Node(2, temp)); // [0]
	temp->children.push_back(new Node(1, temp)); // [1]

	//7
	temp = root->children[1];

	temp->children.push_back(new Node(0, temp)); // [0]

	//8
	temp = root->children[2];

	temp->children.push_back(new Node(3, temp)); //[0]
	temp->children.push_back(new Node(9, temp)); //[1]
	temp->children.push_back(new Node(12, temp)); //[2]
	temp->children.push_back(new Node(13, temp)); //[3]

	printTree(root);

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