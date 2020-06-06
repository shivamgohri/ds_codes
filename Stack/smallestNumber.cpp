#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


string getString(stack<char> &s){
	string ans = "";
	while(!s.empty()){
		char x = s.top();
		ans += x;
		s.pop();
	}

	while( ans[ans.length()-1]=='0' ){
		ans.pop_back();
		if(ans.length()==0){
			return "0";
		}
	}

	int i=0;
	int j=ans.length()-1;

	while(i<j){
		swap(ans[i], ans[j]);
		i++;
		j--;
	}

	return ans;
}

void testcases(){

	string num;
	cin>> num;

	int k;
	cin>> k;

	if(k==num.length()){
		cout<< "0";
		return;
	}

	if(k==0){
		cout<< num;
		return;
	}

	stack<char> s;
	int count = 0;

	for(int i=0; i<num.length(); i++){

		char curr = num[i];

		if(s.empty()){
			s.push(curr);
			continue;
		}

		if( curr<s.top() ){

			while( s.top()>curr && count<k ){
				count++;
				s.pop();
				if(s.empty()){
					break;
				}
			}

			if( count==k ){
				while(i!=num.length()){
					s.push(num[i]);
					i++;
				}

				cout<< getString(s);
				return;
			}
			s.push(curr);
		}
		else{
			s.push(curr);
		}
	}

	while(count!=k){
		s.pop();
		count++;
	}

	cout<< getString(s);
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