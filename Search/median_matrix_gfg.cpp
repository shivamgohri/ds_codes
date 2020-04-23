#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){

		int r,c;
		cin>>r>>c;

		vector<vector<int> > arr(r, vector<int> (c,0));

		for(int i=0;i<r; i++)
			for(int j=0; j<c; j++){
				cin>>arr[i][j];
			}

		int reqPlace = ((r*c)+1)/2;
		int place = 0;

		int minEle = INT_MAX;
		int maxEle = INT_MIN;

		for(int i=0; i<r; i++){

			minEle = min(minEle, arr[i][0]);
			maxEle = max(maxEle, arr[i][c-1]);
		}


		while(maxEle>minEle){

			int mid = (maxEle+minEle)/2;

			place = 0;

			for(int i=0; i<r; i++){
				place += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
			}

			if(place<reqPlace){
				minEle = mid+1;
			}
			else{
				maxEle = mid;
			}
		}

		cout<<minEle<<endl;
	}

	return 0;
}