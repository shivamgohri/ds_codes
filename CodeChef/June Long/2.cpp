#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	string s;
	cin>> s;

	ll ans = 0;

	for(int i=0; i<s.length()-1; i++){		//x-girl, y-boy
		if( s[i]=='x' ){
			if( s[i+1]=='y' ){
				ans++;
				i++;
			}
			else{
				continue;
			}
		}
		else if( s[i]=='y' ){
			if( s[i+1]=='x' ){
				ans++;
				i++;
			}
			else{
				continue;
			}
		}
	}

	cout<< ans;

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