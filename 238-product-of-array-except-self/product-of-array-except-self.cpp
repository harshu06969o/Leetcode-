class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
          int sizeOfArray = nums.size();
          int dingu =1;
           vector<int>prefix(sizeOfArray), suffix( sizeOfArray);
           for( int i =0;i<sizeOfArray;i++){
               if( i==0) prefix[i]=nums[i];
               else {
                prefix[i]= prefix[i-1]*nums[i];
               }

           }
            int total_product = prefix[sizeOfArray-1];
            int right_product =1;
            vector<int>ans(sizeOfArray);
             for( int ind = sizeOfArray-1;ind>=0;ind--){
                   if( ind ==0){
                    ans[ind]=right_product;
                   }
                   else {
                    ans [ind]= prefix[ind-1] * right_product;
                   }
                   right_product*= nums[ind];
             }
             return ans;

        
    }
};