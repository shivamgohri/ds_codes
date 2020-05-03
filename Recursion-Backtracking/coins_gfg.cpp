#include <iostream>
#include <vector>

using namespace std;

void get(vector<int> arr, int i, int sum, int diff, int* flag){
    
    if( *flag == 1 ){
        return;
    }

    if(sum==diff){
        *flag = 1;
        return;
    } 
    
    if(i == arr.size()){       
        return;
    }

    for(int k = i; k<arr.size(); k++){

        sum += arr[k];

        get(arr, k+1, sum, diff, flag);

        sum -= arr[k];
    }

    return;    
}

int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>> n;
        
        int mila;
        cin>>mila;
        
        vector<int> arr(n,0);
        
        int gila = 0;
        
        for(int i=0; i<n; i++){
            cin>> arr[i];
            gila += arr[i];
        }
        
        int diff = (gila - mila);
        
        // cout<<mila<<","<<gila<<","<<diff<<endl;
        
        if( (diff < 0) || (diff&1) ){
            cout<<0<<endl;
        }
        else if(diff==0){
            cout<<1<<endl;
        }
        else{

            diff = diff/2;
            
            int sum = 0;
            
            int flag = 0;
            
            get(arr, 0, sum, diff, &flag );

            if(flag==1){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
            
        } 
    }
    
    return 0;
}
