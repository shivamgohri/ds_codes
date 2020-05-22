#include "trie.h"
#include <bits/stdc++.h>

using namespace std;

string convertToString(unsigned int x){

	string s = "";

	int t = 32;
	while( t-- ){
		
		int first_bit = (x & (1<<31) );
		
		if( first_bit == (1<<31) ){
			s += '1';
		}
		else{
			s += '0';
		}

		x = x<<1;
	}

	return s;
}

int main(){

	Trie t;

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++){
		cin>> arr[i];
		unsigned int x = arr[i];
		t.insert( convertToString(x) );
	}


	int ans = INT_MIN;

	for(int i=0; i<n; i++){

		int curr = 0;

		string curr = convertToString(arr[i]);

		Node* temp = t.root;

		for(int j=0; j<curr.length(); j++){

			if( curr[j]=='0' ){

				if(temp->children.count('1'))

			}

		}

	}



}