#include <iostream>
#include <vector>

using namespace std;
// MAX HEAP

void downheapify(vector<int> &heap, int indx){
	int leftindx = (2*indx) + 1;
	int rightindx = (2*indx) +2;

	if( (leftindx >= heap.size()) and rightindx >= heap.size()){
		return;
	}

	int largestIndx = indx;

	if( leftindx < heap.size() and heap[leftindx] > heap[largestIndx] ){
		largestIndx = leftindx;
	}
	if( rightindx < heap.size() and heap[rightindx] > heap[largestIndx] ){
		largestIndx = rightindx;
	}

	if(largestIndx == indx){
		return;
	}

	int temp = heap[largestIndx];
	heap[largestIndx] = heap[indx];
	heap[indx] = temp;

	downheapify(heap, largestIndx);

	return;	
}

void build_heap_optimized(std::vector<int> &heap, int n){
	for(int i=n-1; i>=0; i--){
		downheapify(heap, i);
	}
	return;
}

void display(std::vector<int> &heap, int n){
	for(int i=0; i<n; i++){
		cout<< heap[i] <<" ";
	}
	cout<< endl;
}

int main(){

	int n;
	cin>> n;

	std::vector<int> heap;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>> x;
		heap.push_back(x);
	}

	build_heap_optimized(heap, n);
	display(heap, n);

	return 0;
}