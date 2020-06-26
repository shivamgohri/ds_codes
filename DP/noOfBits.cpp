#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> dp(num+1, 0);
        
        for(int j(1),i(0),J(2); j<=num; i++, j++){
            if(j==J){
                i = 0;
                J = J<<1;
            }
            dp[j] = dp[i] + 1;
        }
        
        return dp;            
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