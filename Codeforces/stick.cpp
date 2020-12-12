#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define ip(arr) for(int i=0; i<arr.size(); i++) cin>>arr[i];
#define ip1(arr) for(int i=1; i<=arr.size(); i++) cin>>arr[i];
#define op(arr) for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";

#define MAX 10000000
#define mod 100000007


void testcases(){

	int number, kites;
	cin>>number>>kites;
	
	int n = number;
	int k = kites;

	string s;
	cin>>s;

	priority_queue<int>m;
	
	bool f=1;
	int myAnswer=0,cur=0;
	
	for(int i=0;i<s.size();i++){

		if(s[i]=='0')
		{
			myAnswer++;
			cur++;
			f=1;
		}
		else 
		    f=0;

		if(f==0&&cur!=0)
		{
			if(i-cur!=0)
			m.push(cur);
			cur=0;
		}
	}

	int firstVariable=0,secondVariable=0,i=0;

	while(i<s.size()&&s[i]!='1')
		firstVariable++,i++;

	i=s.size()-1;

	while(i>=0&&s[i]!='1')
		secondVariable++,i--;

	if(k==0)
	{
		cout<<myAnswer<<endl;
		return;
	}

	if(k==1)
	{
		if(firstVariable>secondVariable)
		{
		
			myAnswer-=firstVariable;
		}
		else
		{
			myAnswer-=secondVariable;
		}

		cout<<myAnswer<<endl;
		return;
	}

	while(k>0&&(!m.empty()||firstVariable>0||secondVariable>0)&&myAnswer>0){

		if(k==1|| (!m.empty() && (firstVariable>=m.top()||secondVariable>=m.top())) || (k>1&&m.empty()) ) {

			if(firstVariable!=0&&firstVariable>secondVariable ){
				myAnswer-=firstVariable;
				firstVariable=0;
			}
			else if(secondVariable!=0)
			{
				myAnswer-=secondVariable;
				secondVariable=0;
			}
			k--;
		}
		else
		{
			int tempp=m.top();
			myAnswer-=tempp;	
			k-=2;
			m.pop();
		}

	}

	cout<<myAnswer<<endl;
}


int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);    cout.tie(NULL);

	int t = 1;
	cin>> t;

	while(t--){
		testcases();
		// cout<<endl;
	}

	return 0;
}