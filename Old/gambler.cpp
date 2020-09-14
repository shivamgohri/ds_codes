#include <bits/stdc++.h>

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

typedef struct node_s {
	unsigned int value;
	unsigned int child_count;
	struct node_s **children;
} node_t;


node_t* read_tree(void){
	
	int n, r;
	cin>> n >> r;

	node_t* x = new node_t[n];
	node_t** nodes = &x;

	int v, c;

	for(int i=0; i<n; i++){
		cin>> v >> c;
		nodes[i]->value = v;
		nodes[i]->child_count = c;

		node_t* y = new node_t[c];
		node_t** temp = &y;

		int tt;
		for(int j=0; j<c; j++){
			cin>> tt;
			temp[j] = nodes[tt-1]; 
		}

		nodes[i]->children = temp;
	}

	return nodes[r-1];
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