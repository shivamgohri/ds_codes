unsigned long int solve(unsigned int n) 
{ 
    unsigned long int temp[n + 1]; 
  
    temp[0] = temp[1] = 1; 
  
    for (int i = 2; i <= n; i++) { 
        temp[i] = 0; 
        for (int j = 0; j < i; j++) 
            temp[i] = ( temp[i]%mod + ( ( temp[j]%mod * temp[i - j - 1]%mod )%mod )%mod )%mod; 
    } 

    return temp[n]; 
} 
  


int main(){

    int n;
    cin>> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>> arr[i];
    }

    int ans[n];

    for(int i=0; i<n; i++){
        ans[i] = solve( (unsigned long int) arr[i]);
    }

    for(int i=0; i<n; i++){
        cout<< ans[i] <<" ";
    }

    return 0;
}