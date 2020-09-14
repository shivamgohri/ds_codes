#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007

string getString(ull n){
	if(n<10){
		string ans = "0";
		char c = n + '0';
		ans = ans + c;
		return ans;
	}

	string ans = "";
	int last;
	char c;

	while(n>0){
		last = (int) n%10;
		c = last + '0';
		ans = c + ans;
		n = n/10;
	}

	return ans;
}

string getString1(ull n){
	if(n==0){
		return "0";
	}
	string ans = "";
	int last;
	char c;
	while(n>0){
		last = (int) n%10;
		c = last + '0';
		ans = c + ans;
		n = n/10;
	}
	return ans;
}

bool isPalindrome(string s){
	ull start = 0, end = s.length()-1;
	while(start<=end){
		if(s[start]!=s[end]){
			return false;
		}
		start++;
		end--;
	}
	return true;
}


void testcases(){

	ull start, end;
	cin>> start >> end;

	int ans = 0;

	string res, f, s, t;
	ull day, hours, min, sec;

	for(day=start; day<=end; day++){
		
		res = "";
		res = getString1(day);

		for(hours=0; hours<24; hours++){

			f = res + getString(hours);

			for(min=0; min<60; min++){

				s = f + getString(min);

				for(sec=0; sec<60; sec++){

					t = s + getString(sec);

					if(isPalindrome(t)){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
}


int main(){

	//compile
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}