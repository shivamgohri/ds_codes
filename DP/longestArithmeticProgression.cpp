#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int Solution::solve(const vector<int> &A) {
    
    if(A.empty()){
        return 0;
    }
    
    vector<unordered_map<int, int> > arr(A.size());
    
    int ans = 1;
    for(int i=1; i<A.size(); i++){
        for(int j=0; j<i; j++){
            if(j==0){
                arr[i][A[i]-A[j]] = 2;
                ans = max(ans, 2);
                continue;
            }
            
            int diff = A[i]-A[j];
            if( arr[j].find(diff)!=arr[j].end() ){
                arr[i][diff] = max(arr[i][diff], arr[j][diff]+1);
                ans = max(ans, arr[i][diff]);
            }
            else{
                arr[i][diff] = 2;
                ans = max(ans, 2);
            }
        }
    }
    
    return ans;
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