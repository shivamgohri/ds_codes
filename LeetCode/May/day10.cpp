/*
In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<bool> trustsAnyone(N, false);
        vector<int> freq(N, 0);
        
        for(int i=0; i<trust.size(); i++){                
            trustsAnyone[ trust[i][0] - 1 ] = true;
            freq[ trust[i][1] -1 ]++;            
        }
        
        for(int i=0; i<N; i++){
            if( freq[i]==N-1 && trustsAnyone[i]==false ){
                return i+1;
            }
        }
        
        return -1;        
    }
};