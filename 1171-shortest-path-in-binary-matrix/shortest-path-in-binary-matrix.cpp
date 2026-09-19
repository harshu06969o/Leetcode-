 # define   P pair<int,pair<int,int>> 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n = grid.size();
        int distance =0;
         if( grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
         
        priority_queue<P, vector<P> , greater<P>> pq;
        pq.push({1,{0,0}});
        vector<vector<bool>>vis( n, vector<bool>(n,false));
        vis[0][0]= true;
         
        while(!pq.empty()){
             int dis = pq.top().first;
             int row = pq.top().second.first;
             int col = pq.top().second.second;
             pq.pop();
              
             if( row==n-1 && col==n-1) return dis;
              for( int i =-1;i<=1;i++){
                for( int j = -1;j<=1;j++){
                    int nrow = row+ i;
                    int ncol = col+j;
                    if( nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==0){
                        vis[nrow][ncol]=true;
                        pq.push({dis+1,{nrow,ncol}});
                    }

                }
              }

        }
        return -1;
        


        
    }
};