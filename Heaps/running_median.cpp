#include <iostream>
#include <queue>

using namespace std;

int main(){

	int n;
	cin>> n;

	priority_queue<int, vector<int> > max_pq;
	priority_queue<int, vector<int>, greater<int> > min_pq;

	int median = 0;
	for(int i=0; i<n; i++){

		int x;
		cin>> x;

		if(x>median){
			min_pq.push(x);
			if( (min_pq.size()-max_pq.size()) > 1 ){
				int temp = min_pq.top();
				min_pq.pop();
				max_pq.push(temp);
			}
		}
		else{
			max_pq.push(x);
			if( (max_pq.size()-min_pq.size()) > 1 ){
				int temp = max_pq.top();
				max_pq.pop();
				min_pq.push(temp);
			}
		}

		if(min_pq.size()>max_pq.size()){
			median = min_pq.top();
			cout<< median <<endl;
			continue;
		}
		else if(min_pq.size()==max_pq.size()){
			median = (min_pq.top()+max_pq.top())/2;
			cout<< median <<endl;
			continue;
		}
		else{
			median = max_pq.top();
			cout<< median <<endl;
			continue;
		}
	}
}