#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back

bool compare(pair<int, int> p1, pair<int, int> p2){
	return p1.second<p2.second;
}


void testcases(){

	int n;
	cin>> n;

	vector<pair<int, int> > activities;

	for(int i=0; i<n; i++){
		int s, e;
		cin>> s>> e;
		activities.pb( make_pair(s,e) );
	}

	sort( activities.begin(), activities.end(), compare );

	int ans = 1;
	int end = activities[0].second;

	for(int i=1; i<n; i++){
		if(activities[i].first>=end){
			ans++;
			end = activities[i].second;
		}
	}

	cout<< ans;
	activities.clear();
}


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}