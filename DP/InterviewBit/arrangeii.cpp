/*
You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
Example:


Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option.

If a solution is not possible, then return -1.
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

int solve(string A, int i, int b, vector<vector<int> >& dp){
    
    //Base cases
    if( b == (A.length()-i+1) ){
        return 0;
    }

    if( b > (A.length()-i+1) ){
        return -1;
    }
    
    if( i>=A.length() || b<0 ){
        return -1;
    }
    
    //Memoization
    if(dp[i][b]!=-1){
        return dp[i][b];
    }
    
    //if no more stable left, return current ans
    if(b==0){
        int white = 0, black = 0;
        for(int k=i; k<A.length(); k++){
            if(A[k]=='W'){
                white++;
            }
            else{
                black++;
            }
        }
        return dp[i][b] = white*black;
    }
    
    int m = INT_MAX;
    int white = 0, black = 0;
    
    //Applying MCM, and finding best answer
    for(int k=i+1; k<A.length(); k++){
        
        //W = white horse
        if(A[k-1]=='W'){
            white++;
        }
        //else, Black horse
        else{
            black++;
        }
        
        //Recursive call
        int x = solve(A, k, b-1, dp);
        
        if(x!=-1){
            m = min(m, x+(white*black));
        }
    }
    
    return dp[i][b] = m==INT_MAX ? -1 : m;
}


int Solution::arrange(string A, int B) {

	// Base cases    
    if(A.empty()){
        return 0;
    }
    
    //Each block will have only 1 horse, so 0 is answer
    if(B==A.length()){
        return 0;
    }
    
    //Not possible to accomodate
    if(B>A.length()){
        return -1;
    }
    
    vector<vector<int> > dp(A.length()+1, vector<int> (B+1, -1));
    return solve(A, 0, B-1, dp);
}


void testcases(){


}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}