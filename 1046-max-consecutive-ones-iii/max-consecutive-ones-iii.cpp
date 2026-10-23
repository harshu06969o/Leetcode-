class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left =0, right =0;
         int countZeros =0;
          int maxNum =0;
        while( right<n){
             if( nums[right]==0) countZeros++;
             while( countZeros>k){
                if( nums[left]==0) countZeros--;
                left++;
             }
              if( countZeros<=k){
                 maxNum = max( maxNum, right-left+1);



              }
              right++;

        }
         return maxNum;
        
    }
};