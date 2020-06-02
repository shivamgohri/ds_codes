//https://www.geeksforgeeks.org/the-stock-span-problem/

#include <iostream>
#include <stack>

using namespace std;

int main(){

	int t;
	cin>> t;

	while(t--){

		int n;
		cin>> n;

		int* arr = new int[n]();
		int* ans = new int[n]();

		for(int i=0; i<n; i++)
			cin>> arr[i];

		stack<int> s;
		s.push(0);
		ans[0] = 1;

		for(int i=1; i<n; i++){

			while( !s.empty() && arr[s.top()]<=arr[i] ){
				s.pop();
			}

			ans[i] = (s.empty()?i+1:i-s.top());

			s.push(i);
		}

		while(!s.empty())
			s.pop();

		for(int i=0; i<n; i++)
			cout<< ans[i] <<" ";
		cout<<endl;

	}

	return 0;
}