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

	int coins[3] = {0};

	while(n--){

		int x;
		cin>> x;

		if( x == 5 ){
			coins[0]++;
		}
		else if( x == 10 ){
			if( coins[0]==0 ){
				while(n--){
					cin>> x;
				}
				cout<< "NO";
				return;
			}
			else{
				coins[1]++;
				coins[0]--;
			}
		}
		else if( x == 15 ){
			if( coins[1]==0 ){
				if( coins[0]>=2 ){
					coins[0] -= 2;
					coins[2]++;
				}
				else{
					while(n--){
						cin>> x;
					}
					cout<< "NO";
					return;
				}
			}
			else{
				coins[2]++;
				coins[1]--;
			}
		}

	}

	cout<< "YES";
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