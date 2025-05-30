class Solution {
    private:
    int getcmpcost(int node, vector<vector<pair<int,int>>>&adj,vector<bool>&vis,vector<int>&cmp,int cid){
        queue<int>q;
        int ccost=INT_MAX;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int Node=q.front();
            q.pop();
            cmp[Node]=cid;
            for(auto [nbr,w]:adj[Node]){
                ccost&=w;
                if(vis[nbr])continue;
                vis[nbr]=1;
                q.push(nbr);
            }
        }
        return ccost;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto ele:edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        }
        vector<bool>vis(n,0);
        vector<int>cmp(n);
        vector<int>cmpcost;
        int cid=0;
        for(int node=0;node<n;node++){
            if(!vis[node]){
                cmpcost.push_back(getcmpcost(node,adj,vis,cmp,cid));
                cid++;
            }
        }
        vector<int>ans;
        for(auto q:query){
            int s=q[0];
            int e=q[1];
            if(cmp[s]==cmp[e])ans.push_back(cmpcost[cmp[s]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};