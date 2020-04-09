#include <iostream>
#include <vector>

using namespace std;
//MAX HEAP

void downheapify(vector<int> &heap, int size,int indx){
	int leftindx = (2*indx) + 1;
	int rightindx = (2*indx) + 2;

	if( leftindx>=size && rightindx>=size ){
		return;
	}

	int largestIndx = indx;
	if( leftindx<size && heap[leftindx]>heap[largestIndx] ){
		largestIndx = leftindx;
	}
	if( rightindx<size && heap[rightindx]>heap[largestIndx] ){
		largestIndx = rightindx;
	}

	if(largestIndx == indx){
		return;
	}

	int temp = heap[largestIndx];
	heap[largestIndx] = heap[indx];
	heap[indx] = temp;

	downheapify(heap, size, largestIndx);
	return;
}

void build_heap(vector<int> &heap, int n){
	for(int i=n-1; i>=0; i--){
		downheapify(heap, n, i);
	}
	return;
}

void heapsort(vector<int> &heap, int n){
	build_heap(heap, n);

	for(int i=0; i<n-1; i++){
		int temp = heap[n-1-i];
		heap[n-1-i] = heap[0];
		heap[0] = temp;

		downheapify(heap, n-1-i, 0);
	}
	return;
}

void display(vector<int> &heap){
	for(int i=0; i<heap.size(); i++){
		cout<< heap[i] <<" ";
	}
	cout<< endl;
}

int main(){

	int n;
	cin>> n;

	vector<int> heap;
	for(int i=0; i<n; i++){
		int x;
		cin>> x;
		heap.push_back(x);
	}

	heapsort(heap, n);      //ascending order
	display(heap);

	return 0;
}