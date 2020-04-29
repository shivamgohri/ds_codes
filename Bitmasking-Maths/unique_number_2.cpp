#include <iostream>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int m;
		cin>>m;

		int n = (2*m) + 2;

		int* arr = new int[n]();

		int res = 0;

		for(int i=0; i<n; i++){
			cin>> arr[i];
			res = res^arr[i];
		}

		int temp = res;

		int pos = 0;

		while( (temp&1)!=1 ){
			pos++;
			temp = temp>>1;
		}

		int mask = 1<<pos;

		int x = 0, y = 0;

		for(int i=0; i<n; i++){
			if( (arr[i]&mask)>0 ){
				x = x^arr[i];
			}
		}

		y = res^x;

		cout<< min(x,y) <<" "<< max(x,y)<<endl;
	}

	return 0;
}