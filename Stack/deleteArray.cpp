//https://practice.geeksforgeeks.org/problems/delete-array-elements-which-are-smaller-than-next-or-become-smaller/0
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	int n;
	cin>> n;

	int* arr = new int[n]();

	for(int i=0; i<n; i++)
		cin>> arr[i];

	int k;
	cin>> k;

	int count = 0;

	stack<int> s;

	for(int i=0; i<n; i++){

		if(s.empty()){
			s.push(arr[i]);
			continue;
		}

		if( s.top() < arr[i] ){			
			while( s.top()<arr[i] && count<k ){
				count++;
				s.pop();
				if(s.empty()){
					break;
				}
			}
			if(count==k){
				while( i!=n ){
					s.push(arr[i]);
					i++;
				}

				break;
			}
			s.push(arr[i]);
		}
		else{
			s.push(arr[i]);
		}
	}

	vector<int> ans;

	while(!s.empty()){
		ans.pb(s.top());
		s.pop();
	}

	for(int i=ans.size()-1; i>=0; i--){
		cout<< ans[i] <<" ";
	}

}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}