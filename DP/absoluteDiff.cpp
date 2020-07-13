#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){
    
    int n;
    cin>> n;
    
    vector<int> arr(n, 0);
    
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    
    int x = 0, y = 0;
    
    for(int i=1; i<n; i++){
        int a = max( abs(1-1)+x, abs(1-arr[i-1])+y );
        int b = max( abs(arr[i]-1)+x, abs(arr[i]-arr[i-1])+y );
        x = a;
        y = b;
    }
    
    cout<< max(x, y);
    return;
}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}