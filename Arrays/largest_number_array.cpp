//https://www.interviewbit.com/problems/largest-number/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b){
    
    string ab = a.append(b);
    string ba = b.append(a);
    
    return (ab.compare(ba)>0?true:false);
    
}

int main() {
	
	int t;
	cin>> t;
	
	while(t--){
	    
	    int n;
	    cin>> n;
	    
	    string* arr = new string[n]();
	    
	    for(int i=0; i<n; i++)
	        cin>> arr[i];
	        
        sort(arr, arr+n, compare);
        
        for(int i=0; i<n; i++)
	        cout<< arr[i];
        cout<<endl;
	    
	}
	
	return 0;
}