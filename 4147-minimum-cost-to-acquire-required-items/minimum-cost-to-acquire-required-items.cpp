class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
         long long ans =0;
        if( costBoth <= cost1+cost2){
              int dingu = min( need1 , need2);
                ans += ( (long long)costBoth* (long long)dingu);
                need1-= dingu;
                need2-=dingu;

        }
         if ( need1 >0 ){
              ans += (long long)need1* (long long)min( cost1, costBoth);

         }
          if( need2 >0){
             ans += (long long)need2* (long long)min( cost2 , costBoth);
          }
           return ans ;
    }
};