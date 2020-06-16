/*
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
*/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

static bool canEvaluate(string s1, string s2){

    int* freq = new int[26]();

    for(int i=0; i<s1.length(); i++){
        freq[ s1[i] - 'a' ]++;
    }

    for(int i=0; i<s2.length(); i++){
        freq[ s2[i] - 'a' ]--;
    }

    int diff = 0;

    for(int i=0; i<26; i++){
        diff += abs(freq[i]);
    }

    if(diff==1){
        return true;
    }

    return false;
}

static bool compare(string s1, string s2){
    if( s1.length()==s2.length() ){
        return s1<s2;
    }
    return s1.length()<s2.length();
}


int longestStrChain(vector<string>& words) {

    if(words.empty()){
        return 0;
    }
    
    sort(words.begin(), words.end(), compare);

    vector<int> count(words.size(), 1);

    int max_indx = 0;

    for(int i=1; i<words.size(); i++){
        int best = count[i];

        for(int j=0; j<i; j++){
            
            if( words[i].length()==(words[j].length()+1) ){
                if( canEvaluate(words[i], words[j]) ){
                    int n = count[i] + count[j];
                    best = max(n, best);
                }
            }
        }
        count[i] = best;

        if(count[i]>count[max_indx]){
            max_indx = i;
        }
    }

    return count[max_indx];
}


void testcases(){



}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}