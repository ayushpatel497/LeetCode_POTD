class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0; i<flights.size(); i++){
           adj[flights[i][0]].push_back({flights[i][1], flights[i][2]}); 
        }
        vector<int> dis(n,1e9);
        queue<pair <int, pair<int,int>>> q;
        q.push({0, {src,0}});
        dis[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int source= q.front().second.first;
            int dist= q.front().second.second;
            q.pop();
            for(auto it : adj[source]){
                int destination= it.first;
                int wt= it.second;
                if(stops<=k){
                    if(dis[destination] > dist + wt){
                        dis[destination]=  dist + wt;
                        q.push({stops+1, {destination, dist+ wt}});
                    }
                }
                else break;
            }
        }
        if(dis[dst]== 1e9) return -1;
        return dis[dst];
    }
};