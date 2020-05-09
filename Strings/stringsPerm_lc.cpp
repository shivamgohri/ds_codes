//not done!

#include <bits/stdc++.h>

using namespace std;

bool checkInclusion1(string s1, string s2) {  //if s2 has any permutation of s1

	queue<int> q;

	if( s2.length() < s1.length() ){
		return false;
	}    

	int arr[26] = {0};
	int temp[26] = {0};

	for(int i=0; i<s1.length(); i++){
		arr[s1[i]-'a']++;
		temp[s1[i]-'a']++;
	}

	int size = s1.length();
	int tempSize = size;

	for(int i=0; i<s2.length(); i++){

		if( temp[s2[i]-'a']==0 ){	
			// if(tempSize==0){
			// 	for(int j=0; j<26; j++){
			// 		if(temp[j]!=0){
			// 			tempSize = size;
			// 			memcpy(temp, arr, sizeof(arr));
			// 			continue;
			// 		}
			// 	}
			// 	return true;
			// }
			if(!q.empty()){
				i = q.front();
				q.pop();
			}
			tempSize = size;
			memcpy(temp, arr, sizeof(arr));
		}
		else{
			q.push(i);
			tempSize--;
			temp[s2[i]-'a']--;
			if(tempSize==0){
				for(int j=0; j<26; j++){
					if(temp[j]!=0){
						tempSize = size;
						memcpy(temp, arr, sizeof(arr));
						continue;
					}
				}
				return true;
			}
		}
	}

	return false;            
}

bool matches(int occOfS1[26], int occOfS2[26]){

	for(int i=0; i<26; i++){
		if( occOfS2[i]!=occOfS1[i] ){
			return true;
		}
	}

	return true;
}


bool checkInclusion(string s1, string s2) {  

	if( s1.length()>s2.length() ){
		return false;
	}

	int* occOfS1 = new int[26]();

	for(int i=0; i<s1.length(); i++){
		occOfS1[s1[i]-'a']++;
	}

	for(int i=0; i<= (s2.length()-s1.length()); i++){
		int* occOfS2 = new int[26]();

		for(int j=0; j<s1.length(); j++){
			occOfS2[ s2[i+j]-'a' ]++;
		}

		if( matches(occOfS1, occOfS2) ){
			return true;
		}
	}

	return false;
}


int main(){

	string s1,s2;
	cin>> s1 >>s2;

	// cout<<s1<<","<<s2<<endl;

	cout<< checkInclusion(s1, s2) <<endl;

	return 0;
}









