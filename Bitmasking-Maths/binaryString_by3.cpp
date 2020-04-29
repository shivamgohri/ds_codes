//https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		string s;
		cin>>s;

		int o = 0, e = 0;
		bool turn = true;

		for(int i=s.length()-1; i>=0; i--){

			if(turn){
				if(s[i]=='1'){
					e++;
				}
			}
			else{
				if(s[i]=='1'){
					o++;
				}
			}

			turn = !turn;
		}

		int a = abs(o-e)%3;

		if(a==0){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}

	}

	return 0;
}