class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left =0, right =0;
         int maxLen =0;
          int maxFreq =0;
          unordered_map<char,int>mpp;
        while( right<n){
             mpp[s[right]]++;
             maxFreq = max( maxFreq, mpp[s[right]]);
             if( (right-left+1)-maxFreq >k){
                mpp[s[left]]--;
                left++;
             }

            
             
             

             maxLen = max( maxLen, right-left+1);
              
             right++;

        }
         return maxLen;
        
    }
};