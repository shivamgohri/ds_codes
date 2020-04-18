#include <iostream>
using namespace std;

int main() {
    
    int t;
    cin>> t;
    while(t--){
        
        int n;
        cin>> n;
        
        int* arr = new int[n]();
        
        for(int i=0; i<n; i++)
            cin>> arr[i];
            
        int left[n];
        left[0] = arr[0];
        
        for(int i=1; i<n; i++){
            left[i] = max( left[i-1],arr[i] );
        }
        
        int right[n];
        right[n-1] = arr[n-1];
        
        for(int i=n-2; i>=0; i--){
            right[i] = max( right[i+1], arr[i] );
        }
        
        int water = 0;
        for(int i=0; i<n; i++){
            water += min( left[i], right[i] ) - arr[i];
        }
        
        cout<< water <<endl;
        
    }
    
	return 0;
}