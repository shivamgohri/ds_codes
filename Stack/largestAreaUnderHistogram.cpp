//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


void testcases(){

	ull n;
	cin>> n;

	ull* arr = new ull[n]();

	for(ull i=0; i<n; i++)
		cin>> arr[i];

	

	ull best = 0, i;

	for(i=0; i<n; i++){

		if(s.empty()){
			s.push(i);
			continue;
		}

		if( arr[i]>=arr[s.top()] ){
			s.push(i);
		}
		else{
			
			while(arr[i]<arr[s.top()]){
				ull x = s.top();
				s.pop();

				ull n;
				if(s.empty()){
					n = arr[x]*i;
					best = max(n, best);
					break;
				}
				else{
					n = arr[x]*(i - s.top() - 1);
					best = max(n, best);
				}				
			}

			s.push(i);
		}
	}


	while(!s.empty()){

		ull x = s.top();
		s.pop();

		ull n;

		if(s.empty()){
			n = arr[x]*(i);
		}
		else{
			n = arr[x]*(i-s.top()-1);
		}
		best = max(n, best);
	}

	cout<< best;

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