#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){
    
    string x;
    cin>> x;
    
    int a = 0, ab = 0, abc = 0;
    
    for(int i=0; i<x.length(); i++){
        
        if(x[i]=='a'){
            a = 1 + 2*a;   
        }
        else if(x[i]=='b'){
            ab = a + 2*ab;
        }
        else if(x[i]=='c'){
            abc = ab + 2*abc;
        }
    }
    
    cout<< abc;
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