#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        const long long INF = (1LL<<60);
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e: edges) {
            int u=e[0], v=e[1], w=e[2];
            adj[u].push_back({v,w});
        }
        vector<vector<long long>> dist(n, vector<long long>(k+1, INF));
        using State = tuple<long long,int,int>; // dist, node, cnt
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][1]=0;
        pq.emplace(0LL,0,1);
        while(!pq.empty()){
            auto [d,u,cnt]=pq.top(); pq.pop();
            if(d!=dist[u][cnt]) continue;
            if(u==n-1){
                // we could early exit but need minimal across cnt, continue
            }
            for(auto &pr: adj[u]){
                int v=pr.first, w=pr.second;
                int newCnt = (labels[v]==labels[u]) ? cnt+1 : 1;
                if(newCnt>k) continue;
                long long nd = d + w;
                if(nd < dist[v][newCnt]){
                    dist[v][newCnt]=nd;
                    pq.emplace(nd,v,newCnt);
                }
            }
        }
        long long ans=INF;
        for(int c=1;c<=k;c++) ans=min(ans, dist[n-1][c]);
        if(ans==INF) return -1;
        return (int)ans;
    }
};