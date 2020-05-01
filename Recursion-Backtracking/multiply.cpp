#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int mul(int a, int b){

	if(b==0){
		return 0;
	}

	if(b<0){
		b = -b;
		return -(a + mul(a, b-1));
	}
	else{
		return (a + mul(a, b-1) );
	}
}

int convert(string s, int left, int right){

	if(left==right){
		return (s[left]-'0');
	}

	return (s[left]-'0')*pow(10, (right-left) ) + convert(s, left+1, right);
}



int main(){

	// int a, b;
	// cin>> a >>b;

	// cout<< mul(a,b) <<endl;

	string s;
	cin>>s;

	cout<< convert(s, 0, s.length()-1) <<endl;

}