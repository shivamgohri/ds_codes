#include <iostream>
using namespace std;

char getProfession( int level, int position ){

	if(level==1){
		return 'e';
	}

	if( getProfession(level-1, (position+1)/2 ) == 'd' ){
		return (position&1) ? 'd' : 'e';
	}

	return (position&1) ? 'e' : 'd';
}

int main() {

	int t;
	cin>>t;

	while(t--){

		int level, position;
		cin>> level >>position;

		if( level == 1 ){
			cout<<"Engineer"<<endl;
		}
		else{

			char ans = getProfession(level, position);

			if(ans=='e'){
				cout<<"Engineer"<<endl;
			}
			else{
				cout<<"Doctor"<<endl;
			}

		}
	}

	return 0;
}