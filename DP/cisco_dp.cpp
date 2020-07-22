/*

I/p: 
5
1. 10-11:30 -> 100
2. 11-12 -> 500
3. 11:30-1 -> 300
4. 1:05-2 -> 200
5. 1:30-3 -> 700
output :3 , 600

//Taking time in 24-hour format, so Input will be:

5
1. 1000-1130 -> 100
2. 1100-1200 -> 500
3. 1130-1300 -> 300
4. 1305-1400 -> 200
5. 1330-1500 -> 700
output :3 , 600

*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


bool compare(vector<int> v1, vector<int> v2){
	if(v1[0]==v2[0]){
		return v1[1]<v2[1];
	}
	return v1[0]<v2[0];
}


void testcases(){

	int n;
	cin>> n;

	vector<vector<int> > arr(n, vector<int> (3, 0));
	// [i][0] = starting time
	// [i][1] = ending time
	// [i][2] = corresponding points

	int total_points = 0;
	// n = total count

	for(int i=0; i<n; i++){
		cin>> arr[i][0] >> arr[i][1] >> arr[i][2];
		total_points += arr[i][2];
	}

	//sorting acc to start time, then end time
	sort(arr.begin(), arr.end(), compare);

	vector<int> count(n, 0);
	vector<int> prev(n, -1);

	// initializing with corresponding points
	for(int i=0; i<n; i++){
		count[i] = arr[i][2];
	}

	int max_indx = 0;

	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){

			if( arr[i][0]>=arr[j][1] && count[j]+arr[i][2]>count[i] ){
				count[i] = count[j] + arr[i][2];
				prev[i] = j;
			}

			if(count[i]>count[max_indx]){
				max_indx = i;
			}

		}
	}

	int ans = total_points - count[max_indx];

	int num = 1;

	while(prev[max_indx]>=0){
		num++;
		max_indx = prev[max_indx];
	}

	num = n - num;

	cout<< num <<" "<< ans;
	return;
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