class Solution {
    bool topo(int node, vector<int>& vis, vector<int> adj[],
              unordered_set<int>& path, stack<int>& st) {
                vis[node] =1;
                path.insert(node);
                for(auto it:adj[node]){
                    if(!vis[it]){
                        if(topo(it,vis,adj,path,st)) return true;
                    }
                    else {
                       if( path.count(it)) return true;
                    }
                }
                st.push(node);
                path.erase(node);
                return false;
              }

public:
    vector<int> findOrder(int n, vector<vector<int>>& e) {
        vector<int> adj[n];
        for (auto it : e) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        unordered_set<int> path;
        vector<int> vis(n, 0);
        stack<int> st;
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                if (topo(i, vis, adj, path, st))
                    return {};
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};