class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         int n = nums.size();
        unordered_set<int>st( nums.begin(), nums.end());
         int maxi =0;
         
        
        for( int x:st){
            
             
            
            
            


            if( st.find(x-1 ) == st.end() ){
                 int dingu = x;
                 int pillu = 1;
                  
                while( st.find(dingu +1) != st.end()){
                    pillu++;
                    dingu++;

                }
                 maxi = max( maxi , pillu);




            
             }
            
        }
         return maxi;

        

        
    }
};