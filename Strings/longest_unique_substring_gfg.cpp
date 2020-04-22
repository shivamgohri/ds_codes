//https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){

		string s;
		cin>> s;

		std::vector<int> v(256,-1);

		v[(int)s[0]] = 0;

		int curr = 1, max_length = 1, prev_indx;

		for(int i=1; i<s.length(); i++){

			prev_indx = v[(int)s[i]];

			if( prev_indx == -1  || i-curr > prev_indx ){
				curr++;
			}
			else{

				if(curr>max_length){
					max_length = curr;
				}

				curr = i - prev_indx;
			}

			v[(int)s[i]] = i;

		}

		cout<< max_length <<endl;

	}

	return 0;
}