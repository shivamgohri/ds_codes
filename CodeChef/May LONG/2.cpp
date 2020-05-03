/*
As a health expert, Vinay is keeping a close watch on the ongoing pandemic of coronavirus disease (COVID-19). He thought of a different situation where there are 26 types of viruses, named "aorona", "borona", "corona", …, "zorona".

You are given a string S with length N. There are N people (numbered 1 through N) and for each valid i, the i-th person is infected by exactly one type of virus named Siorona (i.e. "corona" with the first letter replaced by the i-th character of S).

You should answer Q queries. In each query:

You are given an integer C denoting the number of available isolation centers.
Each isolation center has an infinite capacity, but with the restriction that two people infected with the same type of virus cannot stay in the same isolation center.
There is also a pending queue with an infinite capacity and there are no restrictions on which people can be in the pending queue.
Initially, the isolation centers and pending queue are empty.
Each of the N people should be placed in either the pending queue or one of the isolation centers.
Since Vinay is busy finding a vaccine, he asks Swapnil to find a way to place the people in the pending queue and isolation centers such that the number of people in the pending queue is the smallest possible.
Help Swapnil find the size of the pending queue in that case.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long

int main(){

	int t;
	cin>> t;

	while(t--){

		int n;
		cin>>n;

		int queries;
		cin>>queries;

		string s;
		cin>>s;

		transform( s.begin(), s.end(), s.begin(), ::tolower );

		int* arr = new int[26]();

		for(int i=0; i<s.length(); i++){
			arr[ s[i]-'a' ]++;
		}

		ll ans, centres;

		while(queries--){

			ans = 0L;

			cin>>centers;

			for(int i=0; i<26; i++){
				ans += ( (arr[i]-centers)<=0 ) ? 0 : (arr[i]-centers);
			}

			cout<<ans<<endl;
		}
	}

	return 0;
}