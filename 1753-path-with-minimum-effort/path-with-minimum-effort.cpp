class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size(),dx[]={-1,1,0,0},dy[]={0,0,1,-1};
        vector<vector<int>> d(n,vector<int>(m,INT_MAX));
        d[0][0]=0;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int cd = -pq.top().first,x = pq.top().second.first,y = pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==m-1) return cd;
            for(int i=0; i<4; i++){
                int newx = x + dx[i],newy = y + dy[i];
                if(newx >= 0 && newy >= 0 && newx < n && newy < m){
                    int new_diff = max(abs(heights[x][y] - heights[newx][newy]),cd);
                    if(new_diff < d[newx][newy]){
                        d[newx][newy] = new_diff;
                        pq.push({-new_diff,{newx,newy}});
                    }
                }
            }
        }
        return 0;
    }
};