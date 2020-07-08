#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

class Solution {
public:
    int numDecodings(string s) {
        
        if(s.empty() || s[0]=='0'){
            return 0;
        }
        
        vector<int> dp(s.length()+1, 1);
        
        for(int i=2; i<=s.length(); i++){
            int op1, op2;
            op1 = op2 = 0;
            
            if(s[i-1]!='0'){
                op1 = dp[i-1];
            }
            
            int num = 0;
            
            if( s[i-2]!='0' ){
                num = (s[i-2]-'0')*10 + s[i-1]-'0';
            }
            
            if(num>0 && num<27){
                op2 = dp[i-2];
            }
            
            dp[i] = op1 + op2;
        }
        
        return dp[s.length()];
    }
};



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