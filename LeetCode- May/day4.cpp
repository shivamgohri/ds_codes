/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to 
*/

class Solution {
public:
    int findComplement(int num) {
        
        if(num==0){
            return 1;
        }
        
        long long ans = 0;
        long long power = 1;
        
        while(num>0){
            int last_bit = num&1;
            
            ans += (last_bit==0?1:0)*power;
            
            power = power*2;
            num = num>>1;            
        }
        
        return (int)ans;        
    }
};