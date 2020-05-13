/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/

int singleNonDuplicate(vector<int>& nums) {
        
    int start = 0;
    int end = nums.size()-1;
    
    while( start<end ){
        
        long long mid = (start+end)/2;
        
        if( end-start>=2 ){
            if( nums[mid-1]==nums[mid] ){
                if(mid%2==1){
                    start = mid+1;
                }
                else{
                    end = mid-2;
                }
            }
            else if( nums[mid+1]==nums[mid] ){
                if( (mid+1)%2==1 ){
                    start = mid+2;
                }
                else{
                    end = mid-1;
                }
            }
            else{
                return nums[mid];
            }
        } 
        else{
            
        }
    }
    
    return nums[start];        
}