
#include<bits/stdc++.h>
using namespace std;
// Solved it on leetcode
// https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1329554052/

int findCheapestPrice(int n, vector<vector<int>>& flights, int src,
    int dst, int k) {
    queue<pair<int, pair<int,int>>> q;                    
    vector<int> cost(n, 1e9);
    cost[src] = 0;
    vector<pair<int, int>> adj[n];
    for(auto it: flights){
        adj[it[0]].push_back({it[2], it[1]});                
    }
    // k, c, n
    q.push({0,{0, src}});

    while(!q.empty()){                
        int stops = q.front().first;
        int c = q.front().second.first;
        int node = q.front().second.second;
        q.pop(); 

        if(stops > k) continue;

        // visiting its neighbors
        for(auto it: adj[node]){
            int adjCost = it.first;
            int adjNode = it.second;                    

            if(adjCost + c < cost[adjNode] && stops <= k){
                cost[adjNode] = adjCost + c;
                q.push({stops + 1, {adjCost + c, adjNode}});
            }
        }

    }
    if(cost[dst] == 1e9) return -1;
    return cost[dst];
}