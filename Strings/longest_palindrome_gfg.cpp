//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s){

	int max_length = 1;
	int start = 0;
	int n = s.length();

	int low, high;

	for(int i=0; i<n; i++){


		//even length palindrome centred at i-1 and i
		low = i-1;
		high = i;

		while( low>=0 && high<n && s[low]==s[high] ){
			if( high-low+1 >max_length ){
				start = low;
				max_length = high-low+1;
			}

			low--;
			high++;
		}


		//odd length palindrome centred around i
		low = i-1;
		high = i+1;

		while( low>=0 && high<n && s[low]==s[high] ){

			if(high-low+1>max_length){
				start = low;
				max_length = high-low+1;
			}

			low--;
			high++;
		}
	}

	string ans = "";

	for(int i=start; i<=start+max_length-1; i++){
		ans = ans + s[i];
	}

	return ans;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		string s;
		cin>> s;

		cout<< longestPalindrome(s) <<endl;

	}

	return 0;
}