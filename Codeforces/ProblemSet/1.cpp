#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007


void exp(){

	int n, k;
	cin>> n >> k;

	int total = 0;
	vector<int> arr(n, 0);	

	for(int i=0; i<n; i++){
		cin>> arr[i];
		total += arr[i];
	}

	if( (total%k) != 0){
		cout<< "No";
		return;
	}

	int req = total/k, count = 0, flag = 0;

	for(int i=0; i<n; i++){

		count += arr[i];

		if(count>req){
			flag = 1;
			break;
		}
		else if(count==req){
			arr[i] = -arr[i];
			count = 0;
			flag = 0;
		}
	}


	if(flag==1){
		cout<< "No";
	}
	else{

		cout<< "Yes\n";

		int prev = 0;
		for(int i=0; i<n; i++){
			if(arr[i]<0){
				cout<< i+1-prev <<" ";
				prev = i+1;
			}
		}
	}

	return;
}


void done(){

	int n;
	cin>> n;

	vector<int> arr(n, 0);

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	stack<int> s;

	for(int i=n-1; i>=0; i--){

		if(s.empty()){
			s.push(arr[i]);
			arr[i] = 0;
		}
		else{

			if(s.top()>=arr[i]){
				arr[i] = s.top() - arr[i] + 1;
			}
			else{
			
				while( !s.empty() && s.top()<arr[i] ){
					s.pop();
				}	

				s.push(arr[i]);
				arr[i] = 0;
			}
		}
	}

	for(int i=0; i<n; i++){
		cout<< arr[i] << " ";
	}
}


void dd(){

	int n;
	cin>> n;

	int total = 0, x;

	for(int i=0; i<n; i++){
		cin>> x;
		total += x;
	}

	int m;
	cin>> m;

	vector<vector<int> > time(m, vector<int> (2, 0));

	for(int i=0; i<m; i++){
		cin>> time[i][0] >> time[i][1];
	}

	if(m==0){
		cout<< -1;
		return;
	}

	x = total;

	int ans, flag = 0;

	for(int i=0; i<m; i++){

		if( x>=time[i][0] && x<=time[i][1] ){
			ans = x;
			flag = 1;
			break;
		}
		else if( x<time[i][0] ){
			ans = time[i][0];
			flag = 1;
			break;
		}
	}

	if(flag==0){
		cout<< -1;
	}
	else{
		cout<< ans;
	}
}


void s(){

	int a, b;
	cin>> a >> b;

	int ans = 0;

	while( (a>=2 && b!=0) || (b>=2 && a!=0) ){

		if( a < b ){
			a++;
			b-=2;
		}
		else{
			b++;
			a-=2;
		}
		ans++;
	}

	cout<< ans;
}


void SJD(){

	int n, m, k;
	cin>> n >> m >> k;

	vector<vector<int> > arr(n, vector<int> (m, 0));
	int x, y, a, b;
	int ans = -1;

	for(int i=0; i<k; i++){

		cin>> x >> y;
		x--; y--;

		if(ans!=-1){
			continue;
		}

		if(arr[x][y]){
			continue;
		}
		else{
			arr[x][y] = 1;
		}

		if( (x-1)>=0 && (y+1)<m ){
			if( arr[x-1][y+1]==1 && arr[x-1][y]==1 && arr[x][y+1]==1 ){
				ans = i+1;
				continue;
			}
		}
		if( (x-1)>=0 && (y-1)>=0 ){
			if( arr[x-1][y-1]==1 && arr[x-1][y]==1 && arr[x][y-1]==1 ){
				ans = i+1;
				continue;
			}
		}
		if( (x+1)<n && (y+1)<m ){
			if( arr[x+1][y]==1 && arr[x+1][y+1]==1 && arr[x][y+1]==1 ){
				ans = i+1;
				continue;
			}
		}
		if( (x+1)<n && (y-1)>=0 ){
			if( arr[x+1][y]==1 && arr[x+1][y-1]==1 && arr[x][y-1]==1 ){
				ans = i+1;
				continue;
			}
		}
	}

	cout<< (ans==-1 ? 0 : ans);
}


void skuvd(){

	int n;
	cin>> n;

	unordered_map<int, int> m;

	int x, ans = 0;

	for(int i=0; i<n; i++){
		cin>> x;
		if(i==x){
			ans++;
		}
		else{
			m[i] = x;
		}
	}

	if(m.size()<2){
		cout<< ans;
		return;
	}

	for(auto it:m){
		if(it.first!=it.second){
			if( m[it.second]==it.first ){
				ans += 2;
				cout<< ans;
				return;
			}
		}
	}

	cout<< ans+1;
	return;
}


void testcskdvskvases(){

	int n, m;
	cin>> n >> m;

	if(n==0){
		if(m==0){
			cout<< 0 <<" "<< 0;
		}
		else{
			cout<< "Impossible";
		}
		return;
	}

	int x = (m<=n) ? n : m;
	int y = (m==0) ? n : n+m-1;

	cout<< x <<" "<< y;
	return;
}


bool isPrime(ull n){

	if(n<=1){
		return false;
	}

	if(n<=3){
		return true;
	}

	if(n%2==0 || n%3==0){
		return false;
	}

	for(ull i=5; i*i <= n; i+=6){
		if( n%i==0 || n%(i+2)==0 ){
			return false;
		}
	}

	return true;
}


void kusdhv(){

	ull a, b;
	cin>> a >> b;

	if( (a-b)==1 ){
		if( isPrime(a+b) ){
			cout<< "YES";
			return;
		}
	}

	cout<< "NO";
	return;
}


void testckjvslknases(){

	int b, g, n, count = 0;
	cin>> b >> g >> n;

	for(int i=0; i<=n; i++){
		if( i<=b && (n-i)<=g ){
			count++;
		}
	}

	cout<< count;
	return;
}


void testcasesondvs(){

	int x, y;
	cin>> x >> y;

	int fx, fy;
	cin>> fx >> fy;

	int ans = 0;

	if( x==fx ){
		ans = 4 + 2*(abs(y-fy)+1);
	}
	else if( y==fy ){
		ans = 4 + 2*(abs(x-fx)+1);
	}
	else{
		ans = 2*(abs(y-fy)+1) + 2*(abs(x-fx)+1);
	}

	cout<< ans;
}


void testcases(){

	int n;
	cin>> n;

	std::vector<int> arr(n, 0);

	for(int i=0; i<n; i++){
		cin>> arr[i];
	}

	for(int i=0; i<n; i++){

		if(i==(n-1)){
			if(arr[i]&1){
				cout<<"NO";
				return;
			}
			else{
				cout<<"YES";
				return;
			}
		}

		if(arr[i]&1){
			if(arr[i+1]==0){
				cout<<"NO";
				return;
			}
			else{
				arr[i+1]--;
			}
		}
	}

	return;
}



int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}