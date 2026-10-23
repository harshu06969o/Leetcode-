class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sizeOfString = s.size();
        unordered_map<int,int>mpp;
         int l=0, r=0;
          int maxi = 0;
         while( l<=r && r<sizeOfString){
            if( mpp.find(s[r]-'a') !=mpp.end()){
                l= max( mpp[s[r]-'a']+1,l);

            }
             maxi= max( maxi , r-l+1);
             mpp[s[r]-'a']= r;
             r++;

         }
          return maxi;
        


        
    }
};