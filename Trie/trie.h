#include <iostream>
#include <unordered_map>

using namespace std;

class Node{

public:

	char data;
	unordered_map<char, Node*> children;
	bool terminal;
	int count;

	Node(char d){
		data = d;
		count = 0;
		terminal = false;
	}

};

class Trie{

public:

	Node* root;

	Trie(){
		root = new Node('\0');
	}


	void insert(string s){

		Node* temp = root;
		for(int i = 0; i < s.length(); i++){

			char ch = s[i];
			if( temp->children.count(ch) ){
				temp = temp->children[ch];
			}
			else{
				Node* n = new Node(ch);
				temp->children[ch] = n;
				temp = temp->children[ch];
			}
		}

		temp->terminal = true;
	}



	bool find( string s ){

		Node* temp = root;
		for(int i=0; i<s.length(); i++){

			if( temp->children.count(s[i]) ){
				temp = temp->children[s[i]];
			}
			else{
				return false;
			}
		}

		if(temp->terminal){
			return true;
		}
		else{
			return false;
		}
	}


};