#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX(int)1e7+5
#define mod 100000007

string modify_str(string s, int x, int a, int y, int b){
	string myString;
	int n=s.length();
	for(int i=0;i<x;i++)
		myString+=s[i];
	for(int i=y;i<=b;i++)
		myString+=s[i];
	for(int i=x;i<=a;i++)
		myString+=s[i];
	for(int i=b+1;i<n;i++)
		myString+=s[i];
	return myString;
}

string solve(string s){
	int n=s.length();
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(s[i]=='0')continue;
			int x=-1, a=-1, y=-1, b=-1, sum=0;
			
			for(int j=i;j<n;j++){
				if(s[j]=='1'){
					if(x==-1)x=j;
					else if(a!=-1 && y==-1)y=j;
					sum++;
				}
				else{
					if(x==-1)continue;
					if(a!=-1 && y==-1){
						x=-1, a=-1, y=-1, b=-1;
						continue;
					}
					sum--;
				}
				if(sum==0){
					if(y==-1)a=j;
					else{
						b=j;
						if(s.substr(x, a-x+1)<s.substr(y, b-y+1))
							break;
						else{
							x=-1, a=-1, y=-1, b=-1;
						}
					}
				}
			}
			if(y!=-1){
				s=modify_str(s, x, a, y, b);
				k=0;
				break;
			}
		}
	}

	return s;
}

string lar(string input) {
	string s=solve(input);
	return s;
}

class base{
public:
	void f1(){
		printf("base::f1\n");
	}
	virtual void f2(){
		printf("base::f2()\n");
	}
};

class derived : public base{
public:
	void f1(){
		printf("derived::f1\n");
	}
	virtual void f2(){
		printf("derived::f2\n");
	}
};


	// derived obj;
	// base* b = &obj;
	// derived* d = &obj;

	// b->f1();
	// d->f1();
	// b->f2();
	// d->f2();


int solve(int n, vector<int>& speed, vector<int>& efficiency, int k){

    typedef unsigned long long ull;

    ull maxi = 0, sum = 0;

    int eff = INT_MAX;

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++)vec.push_back(make_pair(efficiency[i], speed[i]));

    sort(vec.begin(), vec.end());

    multiset<int> sec;

    for (int i = n - 1; i >= 0; i--) {
        if (sec.size() < k) {
            sec.insert(vec[i].second);
            sum += vec[i].second;
            eff = min(eff, vec[i].first);
        } 
        else {
            if (vec[i].second > *sec.begin()) {
                sum -= *sec.begin();
                sum += vec[i].second;
                sec.erase(sec.begin());
                sec.insert(vec[i].second);
                eff = min(eff, vec[i].first);
            }
        }
        maxi = max(maxi, (sum * eff));
    }
    
    return maxi;
}

	// int n;
	// cin>> n;

	// vector<int> speed(n, 0);

	// for(int i=0; i<n; i++){
	// 	cin>> speed[i];
	// }

	// vector<int> efficiency(n, 0);

	// for(int i=0; i<n; i++){
	// 	cin>> efficiency[i];
	// }

	// int k;
	// cin>> k;

	// cout<< solve(n, speed, efficiency, k);

class test{
public:
	bool operator==(test temp);
};

bool test::operator==(test temp){
	if(*this==temp){
		cout<< "Objects are same\n";
		return true;
	}
	else{
		cout<< "no\n";
		return false;
	}
}

void testcases(){
	
	test a1, a2;
	a1==a2;

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