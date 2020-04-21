//https://www.interviewbit.com/problems/add-one-to-number/

#include <iostream>
#include <vector>

using namespace std;

vector<int> addone(vector<int> &A){

	A[A.size()-1]++;
    for(int i=A.size()-1; i>=0; i--){
        
        if( i==0 ){
            if(A[i]==0){
                A.erase(A.begin());
            }
            else if(A[i]>9){
                int rem = A[i]%10;
                int main = A[i]/10;
                A[i] = rem;
                A.insert(A.begin(), main);
                break;
            }
        }
        else if(A[i]>9){
            
            int rem = A[i]%10;
            int main = A[i]/10;
            A[i] = rem;
            A[i-1] += main;
        }
    }
    
    while( A[0]==0 ){
        A.erase(A.begin());
    }
    
    return A;
}

int main(){

	int n;
	cin>> n;

	vector<int> v(n, 0);

	for(int i=0; i<n; i++)
		cin>> v[i];

	vector<int> result = addone(v);

	for(int i=0; i<result.size(); i++){
		cout<< result[i] <<" ";
	}

	return 0;
}