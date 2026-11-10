 class dsu {
        
        vector<int> size;
        vector<int> parent;
         public:

        dsu(int n) {
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int upar(int i) {
            if (i == parent[i])
                return i;
            return parent[i] = upar(parent[i]);
        }

        void unionBySize(int a, int b) {
            int ua = upar(a);
            int ub = upar(b);
             if( ua==ub) return ;

            if (ua != ub) {
                if (size[ua] > size[ub]) {
                    size[ua] += size[ub];
                    parent[ub] = ua;
                } else {
                    size[ub] += size[ua];
                    parent[ua] = ub;
                }
            }
        }
    };
class Solution {
   

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int ansInd = -1;
        dsu DSU(n);

         for( auto &it : edges){
            int u = it[0];
            int v = it[1];
            if ( DSU.upar(u)==DSU.upar(v)){
                 return it;
            }
             DSU.unionBySize( u,v);
         }
        
         return {};
    }
};