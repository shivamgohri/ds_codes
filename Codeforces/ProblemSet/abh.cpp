#include <bits/stdc++.h>

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

// void reconstitue(char* r){

// 	int len = strlen(r);
// 	if(len==0){
// 		return;
// 	}
// 	set<char> s;

// 	for(int i=0; i<len; i++){
// 		if(s.find(r[i])!=s.end()){

// 			int ch = r[i];
// 			if( ch>='a' && ch<='z' ){
// 				ch = ((int)(r[i]-'a') + 1)%26 + 'a';
// 			}
// 			else{
// 				ch = ((int)(r[i]-'A') + 1)%26 + 'A';
// 			}	
// 			cout<<(char)ch<<endl;
// 			while( s.find( (char)ch )!=s.end() ){
// 				if( ch>='a' && ch<='z' ){
// 					ch = ((int)(ch-'a') + 1)%26 + 'a';
// 				}
// 				else{
// 					ch = ((int)(ch-'A') + 1)%26 + 'A';
// 				}
// 			}

// 			r[i] = (char)ch;
// 			s.insert(r[i]);
// 		}
// 		else{
// 			s.insert(r[i]);
// 		}
// 	}
// }

// void solve(){

// 	int prev = INT_MAX, count = 1, ans = 1;

// 	for(int i=1; i<n; i++){
// 		if( arr[i]%arr[i-1]==0 && (arr[i]/arr[i-1])==prev ){
// 			count++;
// 			ans = max(ans, count);
// 		}
// 		else{
// 			if(arr[i]%arr[i-1]==0){
// 				prev = arr[i]/arr[i-1];
// 				count = 1;
// 			}
// 		}
// 	}

// 	cout<<ans;	
// }


// void print_repr2(char left[], char right[], char root){

// 	cout<<"(";
// 	cout<<root;

// 	if(left[ (int)root ]!='\0')
// 	print_repr2(left, right, left[ (int)root] );

// 	if(right[ (int)root ]!='\0')
// 	print_repr2(left, right, right[ (int)root ]);

// 	cout<<")";
// }

// void testkjbdcases(){

// 	// char arr[] = {'C','r','e','e','p','f','i','\0'};
// 	// char* r = arr;
// 	// reconstitue(r);	

//   	int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     	cin>>arr[i];

//     int d=-1;

//     int cur=0,cnt=1;

//     for(int i=1;i<n;i++)
//     {
//     	if(arr[i]%arr[i-1]==0)
//     	{
//     		if(d==arr[i]/arr[i-1])
//     			cur++;
//     		else
//     			{
//     			    d=arr[i]/arr[i-1];
//     			    cnt=1;
//     			}

//     	}
//     	else
//     		cur=1;
//     	cnt=max(cnt,cur);
//     }
//     cout<<cnt;

// }


class Test{
public:
	void setX(int a);
	void print()const;
private:
	int x;
};

void Test::setX(int a){
	x = a;
}

void Test::print() const{
	cout<< x <<endl;
}

void testcases(){

	// union test{
	// 	int i;
	// 	float f;
	// 	char c;
	// };

	// union test *t;

	// t = (union test*)malloc(sizeof(union test));
	// t->f = 10.10f;
	// cout<< t->f;

	// Test*t;
	// Test obj;
	// t = &obj;
	// t->setX(5);
	// t->print();

	vector<char> array;
	char c = 0;
	while(c!='x'){
		cin>> c;
		array.push_back(c);
	}

	cout<<array.at(2);

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