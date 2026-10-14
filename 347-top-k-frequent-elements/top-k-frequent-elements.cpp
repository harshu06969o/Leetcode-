class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int,int>mpp;
        for( int i =0;i<n;i++){
            mpp[nums[i]]++;

        }
          vector<pair<int,int>>dingu;
          for ( auto it: mpp){
             dingu.push_back({it.second, it.first});
          }
           sort( dingu.rbegin(), dingu.rend());
           vector<int>ans;
           for( int i=0;i<k;i++){
            ans.push_back(dingu[i].second);
           }
            return ans;
        

        
    }
};