#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void allPermutations(vector<int>& arr, vector<vector<int> >& result, int index){

	if(index==arr.size()-1){
		result.push_back(arr);
	}
	else{

		for(int i=index; i<arr.size(); i++){

			swap(arr[i], arr[index]);
			allPermutations(arr, result, index+1);
			swap(arr[index], arr[i]);
		}
	}
}

void allPermutationsLexico(vector<int>& arr, vector<vector<int> >& result, int index){

	allPermutations(arr, result, index);
	sort(result.begin(), result.end(), greater<vector<int> >() );
	return;
}

int main(){

	int n;
	cin>>n;

	vector<int> arr(n,0);

	for(int i=0; i<n; i++)
		cin>> arr[i];

	vector<vector<int> > result;

	allPermutationsLexico(arr, result, 0);

	cout<<result.size()<<":"<<endl;
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<< result[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}