#include <iostream>
#include <queue>

using namespace std;

int main(){

	int n;
	cin>> n;

	int* arr = new int[n]();
	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	priority_queue<int, vector<int>, greater<int> > pq(arr, arr+n);
	while(!pq.empty()){
		cout<< pq.top() <<" ";
		pq.pop();
	}

	return 0;
}