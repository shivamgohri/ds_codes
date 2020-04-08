#include <iostream>

using namespace std;
//Max Heap

void upheapify(int* heap, int indx){
	if(indx == 0){
		return;
	}

	int parentindx = (indx-1)/2;
	if(heap[indx] > heap[parentindx]){
		int temp = heap[parentindx];
		heap[parentindx] = heap[indx];
		heap[indx] = temp;

		upheapify(heap, parentindx);
	}
	else{
		return;
	}
}

void display(int* heap, int n){
	for (int i = 0; i < n; i++)
	{
		cout<< heap[i] <<" ";
	}
	cout<< endl;
}

void build_heap(int* heap, int n){
	for(int i=1; i<n; i++){
		upheapify(heap, i);
	}
	return;
}

int main(){

	int n;
	cin>> n;

	int heap[n];
	for (int i = 0; i < n; i++)
	{		
		cin>> heap[i];
	}
	
	build_heap(heap, sizeof(heap)/sizeof(int));
	display(heap, sizeof(heap)/sizeof(int));

	return 0;
}