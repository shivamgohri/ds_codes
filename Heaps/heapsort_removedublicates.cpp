#include <iostream>
#include <vector>
using namespace std;

void downheapify(vector<int> &heap, int size, int indx){
	int leftindx = (2*indx) + 1;
	int rightindx = (2*indx) +2;

	if( leftindx >= size and rightindx >= size){
		return;
	}

	int largestIndx = indx;

	if( leftindx < size and heap[leftindx] > heap[largestIndx] ){
		largestIndx = leftindx;
	}
	if( rightindx < size and heap[rightindx] > heap[largestIndx] ){
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

void display(std::vector<int> &heap, int n){
	for(int i=0; i<n; i++){
		cout<< heap[i] <<" ";
	}
	cout<< endl;
}

void heapsort(vector<int> &heap, int n){
    
    build_heap(heap, n);
    
    int prevSize = heap.size();
    int prev;
    for(int i=0; i<n; i++){
        
        if(prevSize==0){
            break;
        }
        
        if(heap[0]==prev){
            heap[0] = heap[prevSize-1];
            heap.erase(heap.begin() + prev-1);
            prevSize--;
            downheapify(heap, prevSize, 0);
        }
        else{
            int temp = heap[prevSize-1];
            heap[prevSize-1] = heap[0];
            heap[0] = temp;
            prevSize--;
            prev = heap[prevSize];
            downheapify(heap, prevSize, 0);
        }
        
    }
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
    
    heapsort(heap, heap.size());
    display(heap, heap.size());

    return 0;
}