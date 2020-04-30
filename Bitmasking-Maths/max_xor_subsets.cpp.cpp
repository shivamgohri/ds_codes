#include <iostream>
#include <climits>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
	        
	   int n;
	   cin>>n;
	   
	   int* arr = new int[n]();
	   
	   for(int i=0; i<n; i++){
	       cin>>arr[i];
	   }
	   
	   long long subsets = (1<<n) - 1;
	   long long ans = INT_MIN;
	   
	   for(int i=0; i<=subsets; i++){
	       
	       long long curr=0;
	       
	       int j=0;
	       int k = i;
	       while(k>0){
	           
	           if(k&1){
	               curr = curr^arr[j];
	           }
	           
	           j++;
	           k = k>>1;
	       }
	       
	       ans = max(ans, curr);
	   }
	   
	   cout<< ans <<endl;
	    
	}
	
	return 0;
}