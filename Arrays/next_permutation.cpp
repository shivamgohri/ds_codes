#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    
    for(int i=A.size()-1; i>=1; i--){
        
        if(A[i]>A[i-1]){
            
            if( A[i-1]<A[i+1] && i+1<A.size() ){
                int j = i;
                while(A[i-1]<A[j+1] && j+1<A.size()){
                    j++;
                }
                swap(A[j],A[i-1]);
                sort(A.begin()+i, A.end());
                return A;
            }   
            else{
                swap(A[i],A[i-1]);
                sort(A.begin()+i, A.end());
                return A;
            }
        }
    }
    
    sort(A.begin(), A.end());
    return A;
}

int main(){

	int n;
	cin>> n;

	vector<int> A(n,0);

	for(int i=0; i<n; i++)
		cin>> A[i];

	vector<int> result = nextPermutation(A);

	for(int i=0; i<result.size(); i++)
		cout<< A[i]<< " ";
	cout<< endl;
}