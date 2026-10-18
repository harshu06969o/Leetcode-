class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int  ans =0;
          queue<pair<int,int>>pq;
           int n =  grid.size();
           int m = grid[0].size();
            int fresh =0;
           for( int i =0;i<n;i++){
            for( int j =0;j<m;j++){
                if( grid[i][j]==2) pq.push({i,j});
                 if( grid[i][j]==1 ) fresh++; 

            }
           }
           vector<vector<int>>vis( n, vector<int>(m,0));
            int drow[]= {-1,0,1,0};
            int dcol[]= { 0,1,0,-1};
           while(!pq.empty()){
             int sz = pq.size();
             bool dingu = false;
              for( int  i =0;i<sz;i++){
                auto[row,col]= pq.front();
                pq.pop();
                 vis[row][col]= 1;
                 
                for( int i =0;i<4;i++){
                    int nrow = row+drow[i];
                    int ncol = col + dcol[i];
                    if( nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        fresh--;
                        pq.push({nrow,ncol});
                        dingu= true;
                        

                    }

                }

              }
               if( dingu) ans++;
           }
            if( fresh==0 ) return ans;
             else return -1;
        
    }
};