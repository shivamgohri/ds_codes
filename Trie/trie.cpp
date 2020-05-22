#include <bits/stdc++.h>

using namespace std;

class Node{

	public:

		char data;
		unordered_map<char, Node*> children;
		bool terminal;

		Node(char d){
			data = d;
			terminal = false;
		}
};

class Trie{

	Node* root;

	public:

		Trie(){
			root = new Node('\0');
		}


		void insert(char *w){

			Node* temp = root;

			for(int i=0; w[i]!='\0'; i++){

				if( temp->children.count(w[i]) ){
					temp = temp->children[w[i]];
				}
				else{
					Node* n = new Node(w[i]);
					temp->children[w[i]] = n;
					temp = n;
				}
			}

			temp->terminal = true;
		}


		bool find(char *w){

			Node* temp = root;
			for(int i=0; w[i]!='\0'; i++){

				if( temp->children.count(w[i]) ){
					temp = temp->children[w[i]];
				}
				else{
					return false;
				}
			}

			return true;
		}

};


int main(){

	Trie t;

	char word[] = {"sarv"};

	t.insert(word);

	cout<< t.find(word) <<endl;



	return 0;
}