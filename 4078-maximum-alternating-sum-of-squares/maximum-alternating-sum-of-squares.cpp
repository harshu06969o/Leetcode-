class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int  n = nums.size();
        for( int i =0;i<n;i++){
            nums[i]= abs( nums[i]);
        }
        sort( nums.begin(), nums.end());
        long long  ans =0;
        for( int i =0;i<n/2; i++){
            ans -= ( (long long)nums[i]* (long long)nums[i]);
        }
         for( int i =n/2;i<n;i++){
            ans+=( (long long)nums[i]* (long long)nums[i]);
         }
          return ans ;

        
    }
};