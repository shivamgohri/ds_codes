#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int> > customPair;

vector<int> merge(vector<vector<int> > &arr){

	vector<int> output;
	priority_queue<customPair, vector<customPair> , greater<customPair> > pq;
	for(int i=0; i<arr.size(); i++){
		pq.push( make_pair( arr[i][0], make_pair(i,0) ) );
	}
	while(pq.empty()!=true){
		customPair val = pq.top();
		pq.pop();
		int x = val.second.first;
		int y = val.second.second;
		output.push_back(val.first);
		if(y+1<arr[x].size()){
			pq.push( make_pair( arr[x][y+1], make_pair(x,y+1) ) );
		}
	}

	return output;
}

int main(){

	int k, n;   //k arrays, n elements
	cin>> k >> n;
	
	vector< vector<int> > arr(k, vector<int>(n,0) );

	for (int i=0; i<k; i++){
		for(int j=0; j<n; j++){
			cin>> arr[i][j];
		}
	}

	vector<int> output = merge(arr);
	for(int i=0; i<output.size(); i++){
		cout<< output[i] <<" ";
	}
	return 0;
}