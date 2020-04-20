//https://practice.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays/0

#include <iostream>
#include <climits>
#include <vector>

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
            
        for(int i=0; i<n; i++){
            int x;
            cin>> x;
            arr[i] = arr[i] - x;
        }
        
        vector<int> ans(2*n + 1, -2);
        ans[n] = -1;
        
        int count = 0, max_sum = 0;
        
        for(int i=0; i<n; i++){
            
            count += arr[i];
            
            if(ans[n+count] >= -1){
                max_sum = max(max_sum, i - ans[n+count] );
            }
            else{
                ans[n+count] = i;
            }
            
            
        }
        
        cout<< max_sum <<endl;
        
    }
    
	return 0;
}

