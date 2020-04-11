#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> custom;     // first=frequency, second=(int)char

struct CompareHeight { 
    bool operator()(custom p1, custom p2) 
    {  
        return p1.first < p2.first; 
    } 
}; 

int main(){

	int t;
	cin>> t;
	while(t--){

		string s;
		cin>> s;

		int* arr = new int[26]();
		for(int i=0; i<s.length(); i++){
			arr[ (int)s[i]-97 ]++;
		}		

		priority_queue<custom, vector<custom>, CompareHeight > pq;

		for(int i=0; i<26; i++){
			if(arr[i]!=0){
				pq.push( make_pair(arr[i], i) );
			}
		}

		custom prev;
		string output;

		prev = pq.top();
		pq.pop();
		string s1(1, (char)(97+prev.second) );
		output.append(s1);

		while(!pq.empty()){

			if(pq.top().first == 0){
				pq.pop();
				continue;
			}

			custom curr = pq.top();
			pq.pop();
			string s1(1, (char)(97+curr.second) );
			output.append(s1);

			pq.push( make_pair(prev.first-1, prev.second) );
			prev = curr;
		}

		if(output.length() == s.length()){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
}