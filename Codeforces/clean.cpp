#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll tt;  cin>>tt;
	while(tt--)
	{
		int n;  cin>>n;

	  string str; cin>>str;

		int i=0,j=n-1;

		while(str[i]=='0')  ++i;

		while(str[j]=='1')  --j;
		if(i>j){  cout<<str<<endl;

		}else{
		
			string s="";
			for(int l=0;l<i;l++)  s=s+str[l];
			s=s+'0';
			for(int m=j+1;m<n;m++)  s=s+str[m];
			cout<<s<<endl;  
		}
	}

	return 0;
}