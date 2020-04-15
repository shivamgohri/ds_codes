#include <iostream>
#include <climits>

using namespace std;
// KADANE'S ALGO

int main(){
    
    int t;
    cin>> t;
    while(t--){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int curr=0, max_sum=0, m=INT_MIN;
	for(int i=0; i<n; i++){
	    
	    if(arr[i]>m){
	        m = arr[i];
	    }

		curr += arr[i];
		max_sum = max(max_sum, curr);
		if(curr<0){
			curr=0;
		}
	}

    if(max_sum == 0){
        cout<< m <<endl;
    }
    else{
        cout<< max_sum <<endl;
    }
	
    }
    
    return 0;
}