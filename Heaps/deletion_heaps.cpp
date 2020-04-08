#include <iostream>
#include <vector>

using namespace std;
//Max Heap

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

void deletion_heap(vector<int> &heap, int indx){
	heap[indx] = heap[heap.size()-1];
	heap.pop_back();
	downheapift(heap, indx);
}

void upheapify(vector<int> &heap, int indx){
	if(indx == 0){
		return;
	}
	int parentindx = (indx-1)/2;
	if( heap[parentindx] < heap[indx] ){

		int temp = heap[indx];
		heap[indx] = heap[parentindx];
		heap[parentindx] = temp;

		upheapify(heap, parentindx);
	}
	else{
		return;
	}
}


void insert( std::vector<int> &heap, int key ){
	heap.push_back(key);
	upheapify(heap, heap.size()-1);
}

void display(vector<int> &heap){
	for (int i = 0; i < heap.size(); i++)
	{
		cout<< heap[i] <<" ";
	}
	cout<< endl;
	return;
}


int main(){

	std::vector<int> heap;
	int n;
	cin>>n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin>> x;
		insert(heap, x);
	}

	display(heap);

	//heap is build, ask for what element to delete

	int delete_element;
	cin>> delete_element;

	int delete_indx=0;
	for (int i = 0; i < heap.size(); ++i)
	{
		if(heap[i]==delete_element){
			delete_indx = i;
		}
	}

	deletion_heap(heap, delete_indx);

	display(heap);

	return 0;
}