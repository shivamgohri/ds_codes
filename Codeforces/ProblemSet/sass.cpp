#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define ip(arr) for(int i=0; i<arr.size(); i++) cin>>arr[i];
#define ip1(arr) for(int i=1; i<=arr.size(); i++) cin>>arr[i];
#define op(arr) for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";

#define MAX 10000000
#define mod 100000007


// C++ program to create a Complete Binary tree from its Linked List 
// Representation 
#include <iostream> 
#include <string> 
#include <queue> 
using namespace std; 


struct BinaryTreeNode 
{ 
	int data; 
	BinaryTreeNode *left, *right; 
};  

BinaryTreeNode* newBinaryTreeNode(int data) 
{ 
	BinaryTreeNode *temp = new BinaryTreeNode; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void convertList2Binary(ListNode *head, BinaryTreeNode* &root) 
{ 

	queue<BinaryTreeNode *> q; 

	if (head == NULL) 
	{ 
		root = NULL;
		return; 
	} 

	root = newBinaryTreeNode(head->data); 
	q.push(root); 

	head = head->next; 

	while (head) 
	{ 

		BinaryTreeNode* parent = q.front(); 
		q.pop(); 

		BinaryTreeNode *leftChild = NULL, *rightChild = NULL; 
		leftChild = newBinaryTreeNode(head->data); 
		q.push(leftChild); 
		head = head->next; 

		if (head) 
		{ 
			rightChild = newBinaryTreeNode(head->data); 
			q.push(rightChild); 
			head = head->next; 
		} 
 
		parent->left = leftChild; 
		parent->right = rightChild; 
	} 
} 

 
void inorderTraversal(BinaryTreeNode* root) 
{ 
	if (root) 
	{ 
		inorderTraversal( root->left ); 
		cout << root->data << " "; 
		inorderTraversal( root->right ); 
	} 
} 

int main() 
{ 

	BinaryTreeNode *root; 
	convertList2Binary(head, root); 

	cout << "Inorder Traversal of the constructed Binary Tree is: \n"; 
	inorderTraversal(root); 

	return 0; 
} 


vector kadane(vector<int> a)
{
	int max_so_far = 0;

	int max_ending_here = 0;

	int start = 0, end = 0;

	int beg = 0;

	for (int i = 0; i < a.size(); i++)
	{
		max_ending_here = max_ending_here + a[i];

		if (max_ending_here < 0)
		{
			max_ending_here = 0;	
			beg = i + 1;
		}

		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			start = beg;
			end = i;
		}
	}

	vector<int> ans;
	for (int i = start; i <= end; i++)
		ans.push_back(a[i]);

	return ans;
}


void testcases(){

	FILE* fp; 
    char ch; 
    // Open file in Read mode 
    fp = fopen("shivam.txt", "r+"); 

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