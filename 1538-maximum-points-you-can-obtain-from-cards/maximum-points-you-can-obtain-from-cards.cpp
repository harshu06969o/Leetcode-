class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int n =  cardPoints.size();
         int sexy =0;
         for( int i =0;i<k;i++){
            sexy+=cardPoints[i];
         }
         int maxi = sexy;
          int l= k-1;
         for( int dingu = n-1;dingu>= n-k; dingu--){

            sexy -= cardPoints[l];
             sexy+= cardPoints[dingu];
             maxi = max( maxi , sexy);
             l--;
         }
         return maxi;
        
        
    }
};