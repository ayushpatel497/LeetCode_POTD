class Solution {
public:
    int find(int x,vector<int>& parent)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x],parent);
    }

    void Union(int x_parent,int y_parent,vector<int>&rank,vector<int>&parent)
    {
        if(rank[x_parent]>rank[y_parent])
            parent[y_parent]=x_parent;
        else if(rank[y_parent]>rank[x_parent])
            parent[x_parent]=y_parent;
        else
        {
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            int parent_u=find(u,parent);
            int parent_v=find(v,parent);
            if(parent_u!=parent_v)
                Union(parent_u,parent_v,rank,parent);
        }

        return (find(source,parent)==find(destination,parent));
    }
};