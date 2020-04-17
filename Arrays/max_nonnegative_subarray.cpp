#include <iostream>
#include <vector>

using namespace std;

vector<int> maxset(vector<int> &A) {
    
    long curr=0, max_sum=INT_MIN, currstart=0, currend=0, maxstart=-1, maxend=-1;
    
    for(int i=0; i<A.size(); i++){
        
        if(A[i]>=0){
            currend = i;
            curr += A[i];
            if(curr>max_sum){
                maxstart = currstart;
                maxend = currend;
                max_sum = curr;
            }
            else if(curr==max_sum){
                if(currstart<=maxstart){
                    maxstart = currstart;
                    maxend = currend;
                }
            }
        }
        else{
            curr = 0;
            if(i+1<A.size())
                currstart = currend = i+1;
        }
        
        // cout<< currstart<<","<< currend<<","<< maxstart<<","<< maxend<<","<<endl;
    }
    
    vector<int> ans;
    if( maxstart>=0 && maxstart<=maxend && maxend>=maxstart && maxend<A.size() ){
        for(int i=maxstart; i<=maxend; i++){
            ans.push_back(A[i]);
        }
    }
    
    return ans;
}


int main(){

	int n;
	cin>> n;

	vector<int> A(n,0);

	for(int i=0; i<n; i++)
		cin>> A[i];

	vector<int> result = maxset(A);

	for(int i=0; i<result.size(); i++){
		cout<< result[i] <<" ";
	}

	return 0;
}