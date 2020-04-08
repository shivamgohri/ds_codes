#include <iostream>
#include <vector>

using namespace std;
//Max Heap

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

	return 0;
}