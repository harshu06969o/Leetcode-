class Solution {
public:
    int minMoves2(vector<int>& nums) {
         int n = nums.size();
         sort( nums.begin(), nums.end());
         int ind = ( n/2);
         int ele = nums[ind];
          int ans =0;
         for( int x: nums){
            ans+= abs( x-ele);

         }
          return ans;

        
    }
};