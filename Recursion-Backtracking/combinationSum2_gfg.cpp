//https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinations(vector<int>& arr, vector<int>& subset, vector<vector<int> >& result, int auxSum, int sum, int index){

	if(auxSum==sum){
		int flag = 0;
		for(int k=0; k<result.size(); k++){
			if(result[k]==subset){
				flag = 1;
			}
		}
		if(flag==0){
			result.push_back(subset);
		}
	}

	for(int i=index; i<arr.size(); i++){

		if( auxSum+arr[i]<=sum ){

			subset.push_back(arr[i]);

			combinations(arr, subset, result, auxSum+arr[i], sum, i+1);

			subset.pop_back();
		}
	}

	return;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		vector<int> arr(n,0);

		for(int i=0; i<n; i++)
			cin>>arr[i];

		int sum;
		cin>>sum;

		if(n==1){
			if(arr[0]==sum){
				cout<<'('<<arr[0]<<')'<<endl;
			}
			else{
				cout<<"Empty"<<endl;
			}
		}
		else{

			sort(arr.begin(), arr.end());
			vector<int> subset;
			vector<vector<int> > result;

			combinations(arr, subset, result, 0, sum, 0);

			for(int i=0; i<result.size(); i++){
				cout<<'(';
				for(int j=0; j<result[i].size(); j++){
					cout<<result[i][j];
					if(j!=result[i].size()-1){
						cout<<" ";
					}
				}
				cout<<')';
			}
			cout<<endl;

			if(result.empty()){
				cout<<"Empty"<<endl;
			}
		}
	}	

	return 0;
}