/*
There are N people on a street (numbered 1 through N). For simplicity, we'll view them as points on a line. For each valid i, the position of the i-th person is Xi.

It turns out that exactly one of these people is infected with the virus COVID-19, but we do not know which one. The virus will spread from an infected person to a non-infected person whenever the distance between them is at most 2. If we wait long enough, a specific set of people (depending on the person that was infected initially) will become infected; let's call the size of this set the final number of infected people.

Your task is to find the smallest and largest value of the final number of infected people, i.e. this number in the best and in the worst possible scenario.
*/


#include <iostream>
#include <climits>

using namespace std;

int main() {

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;

		int* arr = new int[n]();

		for(int i=0; i<n; i++){
			cin>>arr[i];
		}

		if( n==1 || n==0 ){
			cout<<1<<" "<<1<<endl;
		}
		else{

			int contiguous = 1, minm = 1, maxm = INT_MIN;
			bool first = true;

			for(int i=1; i<n; i++){

				if( arr[i]-arr[i-1] <= 2 ){
					contiguous++;
					maxm = max(maxm, contiguous);
				}
				else{
					if(contiguous<minm){
						minm = contiguous;
					}
					first = false;
					contiguous = 1;
				}

				if(first==true){
					minm = contiguous;
				}
			}

			if(contiguous<minm){
				minm = contiguous;
			}

			if(maxm == INT_MIN){
				maxm = 1;
			}

			cout<<minm<<" "<<maxm<<endl;
		}

	}

	return 0;
}
