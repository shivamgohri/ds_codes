/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(magazine.empty()){
            if(ransomNote.empty()){
                return true;
            }
            else{
                return false;
            }
        }
        
        int* arr = new int[26]();
        
        for(int i=0; i<magazine.length(); i++){            
            arr[ magazine[i]-'a' ]++;          
        }
        
        for(int i=0; i<ransomNote.length(); i++){
            
            int current = (int)ransomNote[i] - 97 ;
            
            if( arr[current]==0 ){
                return false;
            }
            else{
                arr[current]--;
            }            
        }
        
        return true;        
    }
};