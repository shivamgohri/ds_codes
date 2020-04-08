#include <iostream>
#include <vector>

using namespace std;
//MAX HEAP

void downheapify(vector<int> &heap, int indx){

	int leftindx = (2*indx) + 1;
	int rightindx = (2*indx) + 2;

	if( leftindx >= heap.size() && rightindx >= heap.size() ){
		return;
	}

	int largestIndx = indx;
	if( leftindx<heap.size() && heap[leftindx]>heap[largestIndx] ){
		largestIndx = leftindx;
	}
	if( rightindx<heap.size() && heap[rightindx]>heap[largestIndx] ){
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

void upheapify(vector<int> &heap, int indx){

	if(indx == 0){
		return;
	}

	int parentindx = (indx-1)/2;

	if(heap[parentindx] < heap[indx]){
		int temp = heap[parentindx];
		heap[parentindx] = heap[indx];
		heap[indx] = temp;

		upheapify(heap, parentindx);
	}
	else{
		return;
	}
}

void deletion_node(vector<int> &heap, int indx){

	heap[indx] = INT_MAX;

	upheapify(heap, indx);
	heap[0] = heap[heap.size()-1];
	heap.pop_back();

	downheapify(heap, 0);
	return;
}

void display(vector<int> &heap){

	for(int i=0; i<heap.size(); i++){
		cout<< heap[i] <<" ";
	}
	cout<< endl;
	return;
}

int main(){

	int n;
	cin>> n;

	std::vector<int> heap;
	for(int i=0; i<n; i++){
		int x;
		cin>> x;
		heap.push_back(x);
	}

	int deletion_element;
	cin>> deletion_element;

	int deletion_indx;
	for(int i=0; i<n; i++){
		if(heap[i] == deletion_element){
			deletion_indx = i;
		}
	}

	for(int i=1; i<n; i++){
		upheapify(heap, i);
	}

	deletion_node(heap, deletion_indx);
	display(heap);

	return 0;
}