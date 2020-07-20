/*
Find longest Arithmetic Progression in an integer array A of size N, and return its length.

More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.

Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]

Note: The common difference can be positive, negative or 0.



Input Format:

The first and the only argument of input contains an integer array, A.
Output Format:

Return an integer, representing the length of the longest possible arithmetic progression.
Constraints:

1 <= N <= 1000
1 <= A[i] <= 1e9
Examples:

Input 1:
    A = [3, 6, 9, 12]

Output 1:
    4

Explanation 1:
    [3, 6, 9, 12] form an arithmetic progression.

Input 2:
    A = [9, 4, 7, 2, 10]

Output 2:
    3

Explanation 2:
    [4, 7, 10] form an arithmetic progression.
*/

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