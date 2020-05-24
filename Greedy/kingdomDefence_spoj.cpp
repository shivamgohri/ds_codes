#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
#define ll long long
#define pb push_back


void testcases(){

	int x, y, towers;
	cin>> x>> y>> towers;

	if(towers==0){
		cout<< (x*y);
		return;
	}

	vector<int> x1(towers,0), y1(towers,0);

	for(int i=0; i<towers; i++){
		cin>> x1[i];
		cin>> y1[i];
	}

	sort(x1.begin(), x1.end());
	sort(y1.begin(), y1.end());

	int mx = 0, my = 0;

	mx = max(x1[0] - 0 - 1, mx);
	my = max(y1[0] - 0 - 1, my);

	for(int i=1; i<towers; i++){
		mx = max(x1[i] - x1[i-1] - 1, mx);
		my = max(y1[i] - y1[i-1] - 1, my);
	}

	mx = max(x - x1[towers-1], mx);
	my = max(y - y1[towers-1], my);

	cout<<(mx*my);
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