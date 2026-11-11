class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<pair<int,int>>adj[n+1];
         for( int i =0;i<times.size();i++){
             adj[times[i][0]].push_back({times[i][1], times[i][2]});
         }
        vector<int>minT( n+1,1e9);
        
        priority_queue< pair<int,int>,vector< pair<int,int>>, greater< pair<int,int>>>pq;
         pq.push({0, k});
          minT[k]=0;
         while(!pq.empty()){
             int time = pq.top().first;
             int node = pq.top().second;
              pq.pop();
             for( auto it: adj[node]){
                int nNode = it.first;
                int nTime = it.second;
                if( time+nTime < minT[nNode]){
                     minT[nNode]= time+ nTime;
                     pq.push({minT[nNode], nNode});

                }
             }


         }
          int  minTime = 0;
          for( int i=1;i<=n;i++){
              if( minT[i]==1e9) return -1;
            minTime = max( minTime , minT[i]);
          }
            return  minTime;


        
        
    }
};