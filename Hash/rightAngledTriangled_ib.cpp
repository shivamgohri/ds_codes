#define mod 1000000007
#define ull unsigned long long int

int Solution::solve(vector<int> &A, vector<int> &B) {
    
    if(A.size()!=B.size()){
        return 0;
    }
    
    unordered_map<ull, int> x;
    unordered_map<ull, int> y;
    
    for(int i=0; i<A.size(); i++){
        x[A[i]]++;
        y[B[i]]++;
    }
    
    ull ans = 0;
    
    
    for(int i=0; i<A.size(); i++){
        
        ull curr = ( x[A[i]] - 1 )*( y[B[i]] - 1 );
        ans = ans%mod;
        curr = curr%mod;
        ans = (ans + curr)%mod;
        
    }
    
    return (int)ans;
}
