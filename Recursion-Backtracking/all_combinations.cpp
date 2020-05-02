#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void powerSet(vector<int>& arr, vector<int>& subset, vector<vector<int> >& result, int index){

	if(subset.size()!=arr.size()){
		result.push_back(subset);
	}

	for(int i=index; i<arr.size(); i++){

		subset.push_back(arr[i]);

		powerSet(arr, subset, result, i+1);

		subset.pop_back();
	}

	return;
}

void allCombinations(vector<int>& arr, vector<int>& subset, vector<vector<int> >& result, int index){

	result.push_back(subset);

	for(int i=index; i<arr.size(); i++){

		subset.push_back(arr[i]);

		allCombinations(arr, subset, result, i+1);

		subset.pop_back();
	}

	return;
}

void allCombinationsLexico(vector<int>& arr, vector<int>& subset, vector<vector<int> >& result, int index){
	sort(arr.begin(), arr.end());
	allCombinations(arr,subset,result,index);
	// sort(result.begin(), result.end());
	return;
}


int main(){

	int n;
	cin>> n;

	vector<int> arr(n,0);

	for(int i=0; i<n; i++)
		cin>> arr[i];

	vector<vector<int> > result;
	vector<int> subset;

	//allCombinations(arr, subset, result, 0);
	//allCombinationsLexico(arr, subset, result, 0);
	powerSet(arr, subset, result, 0);

	cout<<result.size()<<":"<<endl;
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<< result[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}