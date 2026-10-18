class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        vector<int>adj[numCourses];
         for( int i =0;i<arr.size();i++){
            adj[arr[i][1]].push_back( arr[i][0]);
         }
         queue<int>q;
         vector<int>indegree(numCourses,0);
         for( int i =0;i<numCourses;i++){
            for( auto it:adj[i]){
                indegree[it]++;
            }
         }
         for( int i =0;i<numCourses;i++){
            if( indegree[i]==0)q.push(i);
         }
          vector<int>toposort;
         while(!q.empty()){
            int node = q.front();
         q.pop();
          toposort.push_back(node);

         for( auto it: adj[node]){
             indegree[it]--;
             if(indegree[it]==0) q.push(it);
         }

         }
          return toposort.size()==numCourses;



        
    }
};