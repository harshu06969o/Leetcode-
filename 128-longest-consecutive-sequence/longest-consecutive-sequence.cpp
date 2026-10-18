class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st( nums.begin(), nums.end());
        int cnt =0;
         for( int x: st){
            if( st.find(x-1)!=st.end()) continue;
            else{
                int dingu =0;
                while( st.find(x)!=st.end()){
                    dingu++;
                    x++;
                }
                 cnt = max( cnt, dingu);
            }
         }
          return cnt;

        
    }
};