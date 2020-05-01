#include <iostream>

using namespace std;

void print(long long n){

	if(n==0){return;}

	int temp = n%10;
	print(n/10);

	if(temp==1){cout<<"one ";}
	else if(temp==2){cout<<"two ";}
	else if(temp==3){cout<<"three ";}
	else if(temp==4){cout<<"four ";}
	else if(temp==5){cout<<"five ";}
	else if(temp==6){cout<<"six ";}
	else if(temp==7){cout<<"seven ";}
	else if(temp==8){cout<<"eight ";}
	else if(temp==9){cout<<"nine ";}
	else if(temp==0){cout<<"zero ";}

	return;
}

int main(){

	long long n;
	cin>> n;

	print(n);

	return 0;
}