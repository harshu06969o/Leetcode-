class Solution {
public:
    bool bfs( vector<int>&color , vector<vector<int>>&graph , int node){
         color[node]=1;
         queue<int>q;
         q.push(node);
         while(!q.empty()){
            int curr_node = q.front();
            q.pop();
            for( auto it: graph[curr_node]){
                if( color[it]==-1){
                    color[it]= 1-color[curr_node];
                    q.push( it);
                }
                else if( color[it]==color[curr_node]) return false;
            }
         }
         return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
        
        vector<int>color( graph.size(), -1);
        for( int i =0;i<n;i++){
              if( color[i]==-1){
                if( bfs( color, graph , i)==false) return false;
              }

        }
        return true;
        

        
    }
};