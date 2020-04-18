#include <iostream>
#include <vector>

using namespace std;

vector<int> flip(string A) {
    
    long count = 0, max_sum=0;
    int start=0, end=0, maxstart=INT_MIN, maxend=INT_MIN;
    
    for(int i=0; i<A.length(); i++){
        
        count += (A[i]=='1'?-1:1);
        
        end = i;
        if(count>max_sum && count>0){
            max_sum = count;
            maxstart = start;
            maxend = end;
        }
        
        if(count<0){
            count = 0;
            if(i+1<A.length())
                start = i+1;
                end = i+1;
        }
        
        // cout<<start<<","<<end<<endl;
    }
    
    vector<int> ans;
    if(max_sum==0){
        return ans;
    }
    else{
        ans.push_back(maxstart+1);
        ans.push_back(maxend+1);
        return ans;
    }
    
}

int main(){

	string s;
	cin>> s;

	vector<int> result = flip(s);

	for(int i=0; i<result.size(); i++){
		cout<< result[i] <<" ";
	}

	return 0;
}