/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        if(s.empty()){
            return -1;
        }
        
        vector<int> freq(26, 0);
        vector<int> index(26, -1);
        
        for(int i=0; i<s.length(); i++){
            int pos = s[i]-'a';
            freq[pos]++;
            
            if(index[pos]==-1){
                index[pos] = i;
            }
            else{
                index[pos] = -2;
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0; i<26; i++){
            
            if( freq[i]==1 && index[i]!=-2 ){
                ans = min(ans, index[i]);
            }   
        }
        
        if(ans==INT_MAX){
            return -1;
        }
        
        return ans;             
    }
};

