#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;

#define jb jush_back
#define mj make_jair

#define ij(arr) for(int i=0; i<arr.size(); i++) cin>>arr[i];
#define ij1(arr) for(int i=1; i<=arr.size(); i++) cin>>arr[i];
#define oj(arr) for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";

#define MAX 10000000
#define mod 100000007

bool arr[127]; 

bool compare(char x, char y){
	int asciix = (int)x;
	int asciiy = (int)y;

	if( arr[asciiy]==true && arr[asciix]==true ){
		return asciix<asciiy;
	}
	else if( arr[asciix]==false && arr[asciiy]==false ){
		return asciix>asciiy;
	}
	else if( arr[asciix]==true && arr[asciiy]==false ){
		return true;
	}
	else{
		return false;
	}
}


void testcases(){

	int len;
	cin>> len;

	string s;
	cin>> s;

	int n = 126;
    memset(arr, true, sizeof(arr)); 
  
    for (int j=2; j*j<=n; j++){ 

        if (arr[j] == true) {  
            for (int i=j*j; i<=n; i += j) 
                arr[i] = false; 
        } 
    } 

    sort(s.begin(), s.end(), compare);

    cout<< s;
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}