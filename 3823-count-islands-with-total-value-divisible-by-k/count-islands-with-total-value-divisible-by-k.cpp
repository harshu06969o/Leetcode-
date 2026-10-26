class Solution {
public:
    void bfs( vector<vector<int>>&vis , vector<vector<int>>&grid , long long& dingu , int row , int col){
        int drow[]={-1,0,1,0};
        int dcol[] = { 0,1,0,-1};
        queue<pair<int,int>>q;
        vis[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
             int crow = q.front().first;
             int ccol = q.front().second;
             q.pop();
             dingu+= grid[crow][ccol];
             for( int i =0;i<4;i++){
                int nrow = crow+ drow[i];
                 int ncol =  ccol + dcol[i];
                 if( nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]>0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                 }

             }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
         int cnt =0;
        vector<vector<int>>vis( rows , vector<int>(cols,0));
        for( int i =0;i<rows;i++){
            for( int j =0;j<cols ; j++){
                if(  grid[i][j]>0 && !vis[i][j]){
                     long long dingu =0;
                    bfs( vis , grid , dingu, i , j );
                     if( dingu %k==0) cnt++;
                }
            }
        }
         return cnt;
        
    }
};