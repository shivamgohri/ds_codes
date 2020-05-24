#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back
#define mp make_pair


bool compare(pair<int, int> p1, pair<int, int> p2){
	return p1.first<p2.first;
}



void testcases(){

	int n;
	cin>> n;

	vector<pair<int, int> > pumps;

	for(int i=0; i<n; i++){
		int d,c;
		cin>> d>> c;
		pumps.pb(mp(d,c));
	}

	int D, F;
	cin>> D>> F;

	for(int i=0; i<n; i++){
		pumps[i].first = D - pumps[i].first;
	}

	sort(pumps.begin(), pumps.end(), compare);

	priority_queue<int> pq;

	int prev = 0, x = 0, flag = 0, ans = 0;

	while(x<n){

		if(F>= (pumps[x].first - prev) ) {
			F = F - (pumps[x].first - prev);
			pq.push(pumps[x].second);
			prev = pumps[x].first;
		}
		else {

			if(pq.empty()){
				flag = 1;
				break;
			}

			F += pq.top();
			pq.pop();
			ans++;
			continue;
		}

		x++;
	}

	if(flag==1){
		cout<< -1;
		return;
	}

	D = D - pumps[n-1].first;

	if(F>=D){
		cout<< ans;
		return;
	}

	while(F<D){

		if(pq.empty()){
			flag = 1;
			break;
		}

		F += pq.top();
		pq.pop();
		ans++;
	}

	if(flag==1){
		cout<< -1;
	}
	else{
		cout<< ans;
	}

	return;
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