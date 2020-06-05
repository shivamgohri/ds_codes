//convert infix equation (a+b) to postfix equation (ab+)
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX (int)1e7+5


int prec(char x){
	if(x=='^'){
		return 3;
	}
	else if(x=='*' || x=='/'){
		return 2;
	}
	else if(x=='+' || x=='-'){
		return 1;
	}
	else{
		return -1;
	}
}

void testcases(){

	string s;
	cin>> s;

	string ans = "";

	stack<char> st;
	st.push('N');

	for(int i=0; i<s.length(); i++){

		if( (s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z') ){    //var
			ans += s[i];
		}
		else if(s[i]=='('){                                              //new block
			st.push('(');
		}
		else if(s[i]==')'){												//end block
			while(st.top()!='('){
				char x = st.top();
				st.pop();
				ans += x;
			}
			st.pop();	
		}
		else{																//operator
			while( st.top()!='N' && prec(s[i])<=prec(st.top()) ){
				char x = st.top();
				st.pop();
				ans += x;
			}
			st.push(s[i]);
		}
	}

	while(st.top()!='N'){
		char x = st.top();
		st.pop();
		ans += x;
	}

	cout<< ans;

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