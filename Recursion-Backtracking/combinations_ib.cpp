#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int last_digit, int pos, vector<vector<int> >& result, vector<int>& subset, int max, int size){

	if( pos==size ){
		result.push_back(subset);
		return;
	}

	for(int i=last_digit+1; i<=(max-size+pos+1); i++){

		subset.push_back(i);
		solve(i, pos+1, result, subset, max, size);
		subset.pop_back();
	}

	return;
}

int main(){

	int n, k; //n-max number, k-no. of digits
	cin>> n >>k;

	vector<vector<int> > result;
	vector<int> subset;

	solve(0, 0, result, subset, n, k);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}