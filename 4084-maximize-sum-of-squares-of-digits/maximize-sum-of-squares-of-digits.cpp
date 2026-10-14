class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while( sum >0 && ans.size()<num){
            
              ans+= ( min(sum,9) +'0');
              sum -= min(sum,9);

        }
        while( sum==0 && ans.size()<num){
             ans+='0';
        }
         if( sum!=0) return "";
         else return ans;
        
    }
};