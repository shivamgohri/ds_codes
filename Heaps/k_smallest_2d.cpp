// ATMOST O(NLOG(N))
#include<iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int,int> > customPair;

void print(vector<vector<int> > &arr, int key){

	priority_queue<customPair , vector<customPair>, greater<customPair> > pq;

    int ans=arr[0][0], min = arr[0][0];
    pq.push( make_pair(arr[0][0], make_pair(0,0) ));
    while(key>1){

    	customPair val = pq.top();
    	pq.pop();
    	ans = val.first;
    	int i = val.second.first;
    	int j = val.second.second;
    	if(i+1<arr.size() ){
    		pq.push( make_pair(arr[i+1][j], make_pair(i+1,j) ));
    	}
    	if(j+1<arr[i].size() ){
    		pq.push( make_pair(arr[i][j+1], make_pair(i,j+1) ));
    	}
    	if(arr[i][j]>min){
    		min = ans;
    		key--;
    	}
    }

    cout<< ans <<endl;
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

	for(int i=1; i<=(k*n); i++){
		print(arr, i);
	}    

    return 0;
}