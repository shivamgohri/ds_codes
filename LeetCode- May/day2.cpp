/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
*/

//ACCEPTED

#include <iostream>
#include <string>

using namespace std;

int numJewelsInStones(string J, string S) {

	if(S.empty()){
		return 0;
	}

	int* small = new int[26]();
	int* big = new int[26]();

	for(int i=0; i<S.length(); i++){

		int temp = (int)S[i];

		if( temp>=65 && temp<=90 ){    //big
			big[temp-65]++;
		}
		else{
			small[temp-97]++;
		}
	}

	int ans = 0;

	for(int i=0; i<J.length(); i++){

		int var = (int)J[i];

		if( var>=65 && var<=90 ){
			ans += big[var-65];
		}
		else{
			ans += small[var-97];
		}
	}


	return ans;        
}

int main(){

	string j,s;
	cin>>j>>s;

	cout<< numJewelsInStones(j,s) <<endl;

}