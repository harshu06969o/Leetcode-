class Solution {
public:
    int minMoves(vector<int>& nums) {
         int dingu = *max_element( nums.begin(), nums.end());
         int ans =0;
         for( int x:nums){
            ans+= dingu-x;
         }
          return  ans;
        
    }
};