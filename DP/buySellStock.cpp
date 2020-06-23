#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5

class Solution {			//atmost one time
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()<2){
            return 0;
        }
        
        int i = 0, j = 1, ans = 0;
        
        while(j<prices.size()){
            
            if( prices[j]>=prices[i] ){
                ans = max(ans, prices[j]-prices[i]);
                j++;
            }
            else{
                i = j;
                j++;
            }            
        }
        
        return ans;        
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