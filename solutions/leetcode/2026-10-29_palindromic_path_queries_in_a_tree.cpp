#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;
        Fenwick(int n=0): n(n), bit(n+2,0) {}
        void add(int idx, int val){
            for(; idx<=n; idx+=idx&-idx) bit[idx] ^= val;
        }
        // range xor update [l,r]
        void rangeXor(int l, int r, int val){
            add(l, val);
            add(r+1, val);
        }
        int query(int idx){
            int res=0;
            for(; idx>0; idx-=idx&-idx) res ^= bit[idx];
            return res;
        }
    };
    
    int LOG;
    vector<vector<int>> up;
    vector<int> depth, tin, tout, eulerMask;
    vector<int> initMask; // mask at tin position
    int timer=0;
    vector<int> parent;
    vector<int> charMask; // current char mask per node
    vector<vector<int>> adj;
    
    void dfs(int v, int p, int curMask){
        parent[v]=p;
        depth[v]= (p==-1?0:depth[p]+1);
        up[0][v]= (p==-1?v:p);
        for(int k=1;k<LOG;k++) up[k][v]=up[k-1][up[k-1][v]];
        curMask ^= charMask[v];
        tin[v]=++timer;
        initMask[tin[v]]=curMask;
        for(int to: adj[v]){
            if(to==p) continue;
            dfs(to, v, curMask);
        }
        tout[v]=timer;
    }
    
    int lca(int a, int b){
        if(depth[a]<depth[b]) swap(a,b);
        int diff=depth[a]-depth[b];
        for(int k=LOG-1;k>=0;k--) if(diff>>k &1) a=up[k][a];
        if(a==b) return a;
        for(int k=LOG-1;k>=0;k--){
            if(up[k][a]!=up[k][b]){
                a=up[k][a];
                b=up[k][b];
            }
        }
        return parent[a];
    }
    
    vector<bool> palindromicPathQueries(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, {});
        for(auto &e: edges){
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        LOG = 1;
        while((1<<LOG) <= n) LOG++;
        up.assign(LOG, vector<int>(n));
        depth.assign(n,0);
        tin.assign(n,0);
        tout.assign(n,0);
        initMask.assign(n+1,0);
        parent.assign(n,-1);
        charMask.assign(n,0);
        for(int i=0;i<n;i++) charMask[i]=1<<(s[i]-'a');
        timer=0;
        dfs(0,-1,0);
        
        Fenwick bit(n);
        vector<bool> ans;
        for(const string& qs: queries){
            stringstream ss(qs);
            string type; ss>>type;
            if(type=="update"){
                int node; char c; ss>>node>>c;
                int oldMask = charMask[node];
                int newMask = 1<<(c-'a');
                if(oldMask==newMask) continue;
                int delta = oldMask ^ newMask;
                bit.rangeXor(tin[node], tout[node], delta);
                charMask[node]=newMask;
            }else{ // query
                int u,v; ss>>u>>v;
                int maskU = initMask[tin[u]] ^ bit.query(tin[u]);
                int maskV = initMask[tin[v]] ^ bit.query(tin[v]);
                int w = lca(u,v);
                int lcaMask = charMask[w];
                int pathMask = maskU ^ maskV ^ lcaMask;
                bool ok = (pathMask & (pathMask-1)) == 0;
                ans.push_back(ok);
            }
        }
        return ans;
    }
};